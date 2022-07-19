#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 12;

int n;
int g[N][N];
int f[N + N][N][N];

int main() {
    scanf("%d", &n);

    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c), a || b || c) {
        g[a][b] = c;
    }

    for (int k = 2; k <= n + n; k++) 
        for (int i1 = 1; i1 <= n; i1 ++)
            for (int i2 = 1; i2 <= n; i2 ++) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    int t = g[i1][j1];
                    if (i1 != i2) t += g[i2][j2];

                    int &x  = f[k][i1][i2];
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                }
            }

    printf("%d", f[n * 2][n][n]);

    return 0;
}