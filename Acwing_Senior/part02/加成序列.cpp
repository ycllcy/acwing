#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n;
int path[N];

bool dfs(int u, int dpath) {
    if (u == dpath) return path[u - 1] == n;

    bool st[N] = {0};
    for (int i = u - 1; i >= 0; i--)
        for (int j = u - 1; j >= 0; j--) {
            int s = path[i] + path[j];
            if (s > n || s <= path[u - 1] || st[s]) continue;

            st[s] = true;
            path[u] = s;
            if (dfs(u + 1, dpath)) return true;
        }
    
    return false;
}

int main() {
    path[0] = 1;
    while (cin >> n, n) {
        int dpath = 1;
        while (!dfs(1, dpath)) dpath++;
        for (int i = 0; i < dpath; i++) cout << path[i] << " ";
        cout << endl;
    }
    return 0;
}