#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n;
char g[N][N];
bool st[N][N];
int xa, ya, xb, yb;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool dfs(int xa, int ya) {
    if (g[xa][ya] == '#') return false;
    if (xa == xb && ya == yb) return true;

    st[xa][ya] = true;
    for (int i = 0; i < 4; i++) {
        int a = xa + dx[i], b = ya + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= n) continue;
        if (st[a][b]) continue;

        if (dfs(a, b)) return true;
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%s", g[i]);
        memset(st, 0, sizeof st);

        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);

        if (dfs(xa, ya)) puts("YES");
        else puts("NO");
    }

    return 0;
}