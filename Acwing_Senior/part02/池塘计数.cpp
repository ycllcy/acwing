#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, m;
char g[N][N];
bool st[N][N];
PII q[M];

void dfs(int sx, int sy) {
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;

    while (hh <= tt) {
        PII t = q[hh++];

        for (int i = t.x - 1; i <= t.x + 1; i++)
            for (int j = t.y - 1; j <= t.y + 1; j++) {
                if (i == t.x && j == t.y) continue;
                if (i < 0 || i > n - 1 || j < 0 || j > m - 1) continue;
                if (g[i][j] == '.' || st[i][j]) continue;

                q[++tt] = {i, j};
                st[i][j] = true;
            }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%s", g[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (g[i][j] == 'W' && !st[i][j]) {
                dfs(i, j);
                cnt++;
            }

    printf("%d", cnt);

    return 0;
}