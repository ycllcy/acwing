#include <iostream>

using namespace std;

const int N = 1010;

int n, m, k;
int a[N][N], s[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    a[x1][y1] += c;
    a[x2 + 1][y1] -= c;
    a[x1][y2 + 1] -= c;
    a[x2 + 1][y2 + 1] += c;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            int c;
            scanf("%d", &c);
            insert(i, j, i, j, c);
        }

    while (k --) {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}