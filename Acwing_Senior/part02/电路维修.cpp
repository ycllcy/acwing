#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 510;

int n, m;
char g[N][N];
bool st[N][N];
int dist[N][N];

int bfs() {
    int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
    char cs[] = "\\/\\/";
    int ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0, -1};

    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    deque<PII> q;
    q.push_back({0, 0});
    dist[0][0] = 0;

    while (q.size()) {
        PII t = q.front();
        q.pop_front();

        if (st[t.x][t.y]) continue;
        st[t.x][t.y] = true;

        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m) continue;
            int ga = t.x + ix[i], gb = t.y + iy[i];

            int d = dist[t.x][t.y] + (g[ga][gb] != cs[i]);

            if (d < dist[a][b]) {
                dist[a][b] = d;

                if (g[ga][gb] != cs[i]) q.push_back({a, b});
                else q.push_front({a, b});
            }
        }
    }

    return dist[n][m];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%s", g[i]);

        int t = bfs();

        if (t == 0x3f3f3f3f) puts("NO SOLUTION");
        else printf("%d\n", t);
    }

    return 0;
}