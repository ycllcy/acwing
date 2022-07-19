#include <iostream>

using namespace std;

const int N = 1010;

int n, m, k;
int s[N][N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            scanf("%d", &s[i][j]);
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }

    int x1, y1, x2, y2;
    while (k --) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }

    return 0;
}