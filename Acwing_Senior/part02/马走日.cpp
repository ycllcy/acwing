#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10;

int n, m, x, y;
bool st[N][N];
int ans;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs(int x, int y, int cnt) {
    if (cnt == n * m) {
        ans++;
        return;
    }
    
    st[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int a = x + dx[i], b = y  + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (st[a][b]) continue;

        dfs(a, b, cnt + 1);
    }

    st[x][y] = false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(st, 0, sizeof st);
        scanf("%d%d%d%d", &n, &m, &x, &y);

        dfs(x, y, 1);

        printf("%d", ans);
    }

    return 0;
}