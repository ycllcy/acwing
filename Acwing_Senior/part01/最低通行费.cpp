#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n;
int f[N][N];
int g[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    memset(f, 0x3f, sizeof f);

    f[1][1] = g[1][1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + g[i][j];
        }

    printf("%d", f[n][n]);

    return 0;
}