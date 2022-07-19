#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n;
int g[N][N];
PII q[M];
PII pre[N][N];

void bfs(int sx, int sy) {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    // 由于需要一个状态数组来判断每个点是否被扩展过，我们这里直接使用pre来标记每个点
    
    int hh = 0, tt = 0;
    q[0] = {sx, sy};

    memset(pre, -1, sizeof pre);
    pre[sx][sy] = {0, 0};

    while (hh <= tt) {
        PII t = q[hh++];

        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= n) continue;
            if (g[a][b]) continue;
            if (pre[a][b].x != -1) continue;

            q[++tt] = {a, b};
            pre[a][b] = t;
        }
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    // 由于我们需要输出最短路径，而我们在保存路径时保存的是每个点的上一个点
    // 如果从起点开始宽搜的话，我们在输出时就先需要一个数组来保存路径，然后再把数组输出
    // 这里我们直接从终点开始宽搜，在输出时就可以直接输出了
    bfs(n - 1, n - 1);

    PII end(0, 0);

    while (true) {
        printf("%d %d\n", end.x, end.y);
        if (end.x == n - 1 && end.y == n - 1) break;
        end = pre[end.x][end.y];
    }

    return 0;
}