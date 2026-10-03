#include <stdio.h>

int a[105][105];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int sum = 0;

    for (int i = 0; i < m; i++) {
        for (int p = 0; p < n; p++) {
            scanf("%d", &a[i][p]);
            sum = sum + a[i][p];
        }
    }

    printf("%d\n", sum);
    return 0;
}
