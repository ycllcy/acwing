#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 22, M = 80;

int n, m, k;
int f[N][M];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;

    while (k--) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        for (int i = n; i >= 0; i--)
            for (int j = m; j >= 0; j--)
                // 先看逻辑上是否合法，如果逻辑上合法，再看语法上是否合法，如果逻辑合法而语法不合法，在思考怎样让语法不合法变为合法
                f[i][j] = min(f[i][j], f[max(0, i - a)][max(0, j - b)] + w);
    }

    printf("%d", f[n][m]);

    return 0;
}