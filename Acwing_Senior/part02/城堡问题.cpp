#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 55, M = N * N;

int n, m;
PII q[M];
bool st[N][N];
int g[N][N];

int bfs(int sx, int sy) {
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;
    int res = 1;

    while (hh <= tt) {
        PII t = q[hh++];

        for (int i = 0; i < 4; i++) {
            // 由于每个点的数值之和是多个二的整次幂的数的和，因此这里直接判断这个数的二进制数的每一位是否是1
            if (!(g[t.x][t.y] >> i & 1)) {
                int a = t.x + dx[i], b = t.y + dy[i];
                if (!st[a][b]) {
                    q[++tt] = {a, b};
                    st[a][b] = true;
                    res++;
                }
            }
        }
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &g[i][j]);

    int res = 0, area = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            if (!st[i][j]) {
                area = max(area, bfs(i, j));
                res ++;
            }
    
    printf("%d\n%d\n", res, area);

    return 0;
}