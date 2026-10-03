#include <stdio.h>

int a[10005];

int main() {
    int L, M;
    scanf("%d %d", &L, &M);

    for (int i = 0; i <= L; i++) {
        a[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        for (int j = l; j <= r; j++) {
            a[j] = 0;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= L; i++) {
        if (a[i] == 1) {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
