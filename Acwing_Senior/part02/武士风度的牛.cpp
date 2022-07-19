#include <iostream>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 155, M = N * N;

int n, m;
PII q[M];
int dist[N][N];
char g[N][N];

int bfs() {
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    int sx, sy;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'K')
                sx = i, sy = j;
    
    memset(dist, -1, sizeof dist);

    // 初始化队列
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    dist[sx][sy] = 0;

    // 队列非空，取出队头，扩展队列
    while (hh <= tt) {
        PII t = q[hh++];

        for (int i = 0; i < 8; i++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            // 三个判断条件：是否出界、是否满足题意、是否被扩展过
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (g[a][b] == '*') continue;
            if (dist[a][b] != -1) continue;

            if (g[a][b] == 'H') return dist[t.x][t.y] + 1;

            q[++tt] = {a, b};
            dist[a][b] = dist[t.x][t.y] + 1;
        }
    }

    return -1;
}

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) cin >> g[i];

    cout << bfs() << endl;

    return 0;
}