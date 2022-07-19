#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20;

int n, m;
int w[N];
int sum[N];
int ans = 0x3f3f3f3f;

// 这里的u表示小猫的下标
void dfs(int u, int k) {
    // 最优性剪枝
    if (k >= ans) return;   
    if (u == n) {
        ans = k;
        return;
    }

    for (int i = 0; i < k; i++) {
        if (sum[i] + w[u] <= m) {
            sum[i] += w[u];
            dfs(u  + 1, k);
            sum[i] -= w[u]; // 恢复现场
        }
    }

    sum[k] = w[u];
    dfs(u + 1, k + 1);
    sum[k] = 0; // 恢复现场
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);

    // 优化搜索顺序
    sort(w, w + n);
    reverse(w, w + n);

    dfs(0, 0);

    printf("%d", ans);

    return 0;
}