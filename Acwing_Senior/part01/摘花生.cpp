#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
int f[N][N];
int g[N][N];

int main() {
    int T;
    cin >> T;

    while (T--) {
        memset(f, 0, sizeof f);
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> g[i][j];

        f[1][1] = g[1][1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j];

        cout << f[n][m] << endl;
    }

    return 0;
}