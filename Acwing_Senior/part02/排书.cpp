#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 16;

int n;
int q[N];
int w[5][N];

int f() {
    int tot = 0;
    for (int i = 0; i + 1 < n; i++)
        if (q[i + 1] != q[i] + 1)
            tot ++;
    return (tot + 2) / 3;
}

bool dfs(int depth, int max_depth) {
    if (depth + f() > max_depth) return false;
    if (f() == 0) return true;

    for (int len = 1; len <= n; len ++)
        for (int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            for (int k = r + 1; k < n; k++) {
                memcpy(w[depth], q, sizeof q);
                int y = l;
                for (int x = r + 1; x <= k; x ++, y ++) q[y] = w[depth][x];
                for (int x = l; x <= r; x ++, y++) q[y] = w[depth][x];
                if (dfs(depth + 1, max_depth)) return true;
                memcpy(q, w[depth], sizeof q);
            }
        } 
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> q[i];

        int depth = 0;
        while (depth < 5 && !dfs(0, depth)) depth++;

        if (depth >= 5) cout << "5 or more" << endl;
        else cout << depth << endl;
    }

    return 0;
}