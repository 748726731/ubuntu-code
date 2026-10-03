#!/usr/bin/env bash
# ============================================================
#  code-c/build.sh   —— 编译本目录源码到 ./运行/c/
#
#  用法：
#    ./build.sh             编译所有已改动的源码
#    ./build.sh 100以内素数  只编译指定文件（可写多个）
#    ./build.sh run 100以内素数   编译并立即运行（VSCode 一键运行用）
#    ./build.sh debug 100以内素数  用 -g -O0 编译，供 F5 调试用
#    ./build.sh all         强制重编全部
#    ./build.sh clean       删除 ./运行/c/ 下所有可执行文件
#
#  规则：
#    code-c/xxx.cpp  ->  code-c/运行/c/xxx-exe
#    源码与可执行文件分开存放，互不干扰
# ============================================================
set -u

HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
RUN="$HERE/运行/c"
CXXFLAGS=(-std=c++17 -O2 -Wall)

# ---------- 可选：顺手把源码与备份统一转成 UTF-8 ----------
# 只处理非 UTF-8 的文件（纯 ASCII 不会被改动）。
# 如果哪天从 Windows 拷进来 GBK 文件，跑一次 build.sh 就会自动转正。
convert_to_utf8() {
    command -v python3 >/dev/null 2>&1 || return 0
    python3 - "$HERE" <<'PY'
import os, sys
root = sys.argv[1]
n = 0
for sub in ("", "bak/c"):
    d = os.path.join(root, sub)
    if not os.path.isdir(d):
        continue
    for name in sorted(os.listdir(d)):
        if not name.endswith((".cpp", ".c", ".cpp.bak", ".c.bak")):
            continue
        p = os.path.join(d, name)
        data = open(p, "rb").read()
        try:
            data.decode("utf-8")
        except UnicodeDecodeError:
            open(p, "wb").write(data.decode("gbk").encode("utf-8"))
            print(f"  [转UTF-8] {sub + '/' if sub else ''}{name}")
            n += 1
if n:
    print(f"  共转换 {n} 个文件")
PY
}

# ---------- clean ----------
if [ "${1:-}" = "clean" ]; then
    n=0
    if [ -d "$RUN" ]; then
        for f in "$RUN"/*-exe; do
            [ -e "$f" ] || continue
            rm -v "$f"; n=$((n+1))
        done
    fi
    echo "已删除 $n 个可执行文件"
    exit 0
fi

# ---------- debug：用 -g -O0 编译（供 F5 调试调用）----------
if [ "${1:-}" = "debug" ]; then
    shift
    # 解析源码：先按原名找，找不到再补 .cpp。
    # 注意必须排除「无扩展名」的同名文件（可能是编译产物），否则会把
    # 二进制文件当成源码传给 g++，报出 "invalid version 3" 这类怪错。
    arg="${1:-}"
    src=""
    for cand in "$HERE/$arg.cpp" "$HERE/$arg" "$HERE/$arg.c"; do
        [ -f "$cand" ] || continue
        case "$cand" in *.cpp|*.c) src="$cand"; break ;; esac
    done
    if [ -z "$src" ]; then
        echo "找不到源码: $arg（需要 $arg.cpp）" >&2
        exit 1
    fi
    name="$(basename "$src" .cpp)"
    out="$RUN/$name-exe"
    mkdir -p "$RUN"
    convert_to_utf8
    echo "调试编译 $name（-g -O0）..."
    g++ -std=c++17 -g -O0 -Wall "$src" -o "$out" || { echo "编译失败" >&2; exit 1; }
    echo "编译完成，交给 gdb"
    exit 0
fi

# ---------- run：编译并立即运行（供 VSCode 一键运行调用）----------
if [ "${1:-}" = "run" ]; then
    shift
    # 解析源码：先按原名找，找不到再补 .cpp。
    # 注意必须排除「无扩展名」的同名文件（可能是编译产物），否则会把
    # 二进制文件当成源码传给 g++，报出 "invalid version 3" 这类怪错。
    arg="${1:-}"
    src=""
    for cand in "$HERE/$arg.cpp" "$HERE/$arg" "$HERE/$arg.c"; do
        [ -f "$cand" ] || continue
        case "$cand" in *.cpp|*.c) src="$cand"; break ;; esac
    done
    if [ -z "$src" ]; then
        echo "找不到源码: $arg（需要 $arg.cpp）" >&2
        exit 1
    fi
    name="$(basename "$src" .cpp)"
    out="$RUN/$name-exe"
    mkdir -p "$RUN"
    convert_to_utf8
    if [ -e "$out" ] && [ "$out" -nt "$src" ]; then
        echo "编译 $name ...（未改动，跳过）"
    else
        echo "编译 $name ..."
        g++ "${CXXFLAGS[@]}" "$src" -o "$out" || { echo "编译失败，未运行" >&2; exit 1; }
    fi
    echo "运行 运行/c/$name-exe"
    echo "----------------------------------------"
    # 切到本目录再执行，保证相对路径和输入输出行为稳定
    cd "$HERE" && exec "$out"
fi

mkdir -p "$RUN"
convert_to_utf8

# ---------- 决定要编译哪些文件 ----------
# 复用一个解析函数：只接受真正以 .cpp/.c 结尾的文件，
# 避免把「无扩展名的同名编译产物」误当源码（会报 invalid version 3）
resolve_src() {
    local arg="$1" cand
    for cand in "$HERE/$arg.cpp" "$HERE/$arg" "$HERE/$arg.c"; do
        [ -f "$cand" ] || continue
        case "$cand" in *.cpp|*.c) printf '%s' "$cand"; return 0 ;; esac
    done
    return 1
}

declare -a targets=()
force_all=0
if [ "${1:-}" = "all" ]; then
    force_all=1
    while IFS= read -r -d '' f; do targets+=("$f"); done \
        < <(find "$HERE" -maxdepth 1 -type f -name '*.cpp' -print0 | sort -z)
elif [ $# -gt 0 ]; then
    for arg in "$@"; do
        if src="$(resolve_src "$arg")"; then
            targets+=("$src")
        else
            echo "找不到源码: $arg（需要 $arg.cpp）" >&2
            exit 1
        fi
    done
else
    while IFS= read -r -d '' f; do targets+=("$f"); done \
        < <(find "$HERE" -maxdepth 1 -type f -name '*.cpp' -print0 | sort -z)
fi

ok=0; skip=0; fail=0
for src in "${targets[@]}"; do
    name="$(basename "$src" .cpp)"
    out="$RUN/$name-exe"

    # 增量：源码没变就不重编
    if [ "$force_all" -eq 0 ] && [ -e "$out" ] && [ "$out" -nt "$src" ]; then
        printf '  \033[90m跳过\033[0m  %s（未改动）\n' "$name"
        skip=$((skip+1)); continue
    fi

    err="$(mktemp)"
    if g++ "${CXXFLAGS[@]}" "$src" -o "$out" 2>"$err"; then
        printf '  \033[32m成功\033[0m  %s  ->  运行/c/%s-exe\n' "$name" "$name"
        grep -q 'warning:' "$err" && sed 's/^/            /' "$err" | grep 'warning:' | head -3
        ok=$((ok+1))
    else
        printf '  \033[31m失败\033[0m  %s\n' "$name"
        sed 's/^/            /' "$err" | head -12
        rm -f "$out"
        fail=$((fail+1))
    fi
    rm -f "$err"
done

echo
echo "======================================"
printf '  成功 %d   跳过 %d   失败 %d\n' "$ok" "$skip" "$fail"
echo "  输出目录: $RUN"
echo "======================================"
[ "$fail" -eq 0 ]
