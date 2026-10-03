ubuntu-code

Ubuntu 上的 C、C++、Qt + OpenCV 练习代码。练手用，顺手放仓库备份。

[目录结构]

ubuntu-code/
├── code-c/          C 语言练习
├── code-c++/        C++ 练习
└── Qt/              Qt + OpenCV 小项目
    ├── background4.jpg
    ├── camera-using/  摄像头虚拟背景
    └── koutu/         图片颜色分离

[环境]

系统：Ubuntu 26.04 LTS
编译器：g++，-std=c++17
Qt：Qt 6（qt6-base-dev）
OpenCV：OpenCV 4（libopencv-dev）
判断依赖是否装好：pkg-config --modversion opencv4
装依赖：sudo apt install qt6-base-dev libopencv-dev
注意：code-c 和 code-c++ 不需要上面两个依赖，只用 g++

[code-c]

C 语言练习：18 个 .cpp
素数：100以内素数.cpp、前50素数.cpp、前30素数-自定义函数.cpp、素数检验.cpp、数组找前一百个素数.cpp
数组矩阵：数组.cpp、矩阵求和.cpp、上三角矩阵.cpp、棋盘数组判定胜负.cpp
字符串结构体：strncpy.cpp、struct.cpp、typedef.cpp、加逗号.cpp
循环输入：for循环.cpp
综合：扫雷.cpp、校门外的树.cpp、整数分解-已封装.cpp、需要多少张纸钱付款-已封装.cpp
命名：带"-已封装"的是逻辑封成函数之后的版本

[code-c++]

C++ 练习：13 个 .cpp
容器字符串：vector.cpp、vector1.1.cpp、getline-substr.cpp、to_string（i）.cpp
语法特性：c++bool.cpp、c++struct.cpp、c++ &.cpp（引用和取地址）、cin-cout.cpp
算法题：Bob First Search.cpp、斗兽棋.cpp、凯撒加密.cpp、简写单词-a[0][0].cpp、test蒙题.cpp
命名：带空格、括号、&、[] 的是早期随手起的，不影响编译，暂不改

[编译方式]

位置：code-c 和 code-c++ 各有一个 build.sh
规则：源码在目录下，编译产物进 运行/ 子目录，不污染源码
输出：code-c/运行/c/原名-exe，code-c++/运行/c++/原名-exe
默认：./build.sh 增量编译，只编改动过的
指定文件：./build.sh 扫雷
编译并运行：./build.sh run 扫雷
调试编译：./build.sh debug 扫雷，用 -g -O0，供 gdb 或 VS Code F5
强制全部重编：./build.sh all
清理产物：./build.sh clean
不用脚本：g++ -std=c++17 -Wall 扫雷.cpp -o 运行/c/扫雷-exe
VS Code：打开 code-c 或 code-c++ 文件夹后 Ctrl+Shift+B

[Qt 项目]

编译：cd Qt/camera-using，qmake6 && make
运行：./build/unknown-Debug/camera-using
Qt Creator：直接打开对应 .pro 文件

camera-using：调摄像头，把 HSV 落在布色域的区域替换成 Qt/background4.jpg，按 q 退出，需要摄像头
koutu：读图片做 HSV 分离显示
koutu 已知问题：源码里图片路径是 D:/work/shuai.jpg，Windows 遗留路径，Ubuntu 下不存在，需自备图片并改路径
移植说明：两个工程都来自同一个 Windows 版本，.pro 里 OpenCV 路径已从硬编码 D:/Opencv/... 改成 pkg-config

[不进仓库的目录]

运行/：build.sh 的产物，跑一次 ./build.sh 重新生成
build/：Qt Creator 的编译目录，含 clangd 索引缓存
bak/：手动复制的旧版本，其中两个文件在源码目录已无对应版本
.pro.user / .qtcreator/：Qt Creator 记录的本机配置，换机器失效
规则：以上都写在 .gitignore 里

[Git 常用指令]

看状态：git status
看改动内容：git diff
看暂存改动：git diff --cached
暂存全部：git add -A
暂存指定：git add 文件名
提交：git commit -m "说明"
提交并暂存已跟踪文件：git commit -am "说明"
推送到远程：git push
首次推送：git push -u origin main
拉取远程：git pull
看历史：git log --oneline
看最近5条：git log --oneline -5
看某次改动：git show 提交号
看某次文件列表：git show --stat 提交号
看某文件修改历史：git log -p 文件名
看某行最后谁改的：git blame 文件名
取消暂存：git reset
撤销文件修改：git restore 文件名
改最近一次说明：git commit --amend -m "新说明"
查提交号：git rev-parse HEAD
查看某文件是否被忽略：git check-ignore -v 文件路径
看被忽略的文件：git status --ignored
看远程地址：git remote -v

日常三步：git add -A，git commit -m "说明"，git push

[Git 配置]

配置身份：git config --global user.name "748726731"
配置邮箱：git config --global user.email "748726731@users.noreply.github.com"
中文不乱码：git config --global core.quotepath false
看全部配置：git config --global --list
认证方式：HTTPS + Personal Access Token，2021 年后 GitHub 不接受账号密码
令牌格式：ghp_ 开头，生成地址 github.com/settings/tokens，权限至少勾 repo
