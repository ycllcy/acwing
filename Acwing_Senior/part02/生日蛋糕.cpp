#include <iostream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 25;

int n, m;
int mins[N], minv[N];
int r[N], h[N];
int ans = 0x3f3f3f3f;

void dfs(int u, int v, int s) {
    if (v + minv[u] > n) return;
    if (s + mins[u] >= ans) return;
    if (s + 2 * (n - v) / r[u + 1] >= ans) return;

    if (!u) {
        if (v == n) ans = s;
        return;
    }

    for (int i = min(r[u + 1] - 1, (int) sqrt(n - v)); i >= u; i--)
        for (int j = min(h[u + 1], (n - v) / (i * i)); j >= u; j--) {
            int t = 0;
            if (u == m) t = i * i;
            r[u] = i, h[u] = j;
            dfs(u - 1, v + i * i * j, s + t + 2 * i * j);
        }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }

    r[m + 1] = h[m + 1] = 0x3f3f3f3f;

    dfs(m, 0, 0);
    
    cout << ans << endl;

    return 0;
}