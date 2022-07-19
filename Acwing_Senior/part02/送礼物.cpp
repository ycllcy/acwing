#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 50, M = 25;

int n, m, k;
int w[N];
int weights[1 << 25], cnt = 1;
int ans;

void dfs1(int u, int s) {
    if (u == k) {
        weights[cnt++] = s;
        return;
    }

    dfs1(u + 1, s);
    if (s + w[u] <= m) dfs1(u + 1, s + w[u]);
}

void dfs2(int u, int s) {
    if (u == n) {
        int l = 0, r = cnt - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (weights[mid] <= m - s) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, weights[l] + s);
        return;
    }

    dfs2(u + 1, s);
    if (s + w[u] <= m) dfs2(u + 1, s + w[u]);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> w[i];

    sort(w, w + n);
    reverse(w, w + n);

    k = n >> 1 + 2;
    dfs1(0, 0);

    sort(weights, weights + cnt);
    cnt = unique(weights, weights + cnt) - weights;

    dfs2(k, 0);

    cout << ans << endl;

    return 0;
}