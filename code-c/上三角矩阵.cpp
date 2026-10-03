#include <stdio.h>

int a[12][12];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int cnt = 0;                 /* ← 就是这里，少了 " = 0" */
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < i; p++) {
            if (a[i][p] == 0) {
                cnt++;
            }
        }
    }

    int standard = 0;
    for (int i = 0; i < n; i++) {
        standard = standard + i;
    }

    if (cnt == standard) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
