#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, m;
// 输入数据没有空格，无法使用int读入，因此使用字符串读入
char g[N][N];
PII q[M];
int dist[N][N];

void bfs() {
    memset(dist, -1, sizeof dist);
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    // 把多源最短距离通过设置一个虚拟点转化为单源最短距离
    // 初始化时把所有格子上为1的点放到队列中，到源点的距离为0，这样就相当于时设置了一个虚拟源点，转化成了单元最短距离
    // 这里初始化队列时所有格子上为1的点就相当于是单源最短距离中通过一个已经入队的源点（在这个题中是虚拟源点）扩展的第二层
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '1') {
                q[++tt] = {i, j};
                dist[i][j] = 0;
            }

    while (hh <= tt) {
        PII t = q[hh++];

        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i], b = t.y + dy[i];

            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (dist[a][b] != -1) continue;
            
            q[++tt] = {a, b};
            dist[a][b] = dist[t.x][t.y] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%s", g[i]);

    bfs();

    return 0;
}