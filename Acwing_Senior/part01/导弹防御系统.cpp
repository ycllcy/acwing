// 使用深搜记得要恢复现场
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int n;
int h[N];
int up[N], down[N];
int ans;

void dfs(int u, int su, int sd) {
    if (su + sd >= ans) return;
    if (u == n) {
        ans = min(ans, su + sd);
        return;
    }

    int k = 0;
    while (k < su && up[k] >= h[u]) k++;
    if (k < su) {
        int t = up[k];
        up[k] = h[u];
        dfs(u + 1, su, sd);
        up[k] = t;
    } else {
        // 这里不需要恢复现场，因为k已经大于等于su了，回溯之后不会用到大于等于su的数据
        // 就算后面会用到大于等于su的数据，也是对原有的数据进行覆盖，不会使用那上面的值
        // 因此不必恢复现场
        // 恢复现场只需要恢复到本次深搜之前的状态
        // 如果在进入本次深搜之前改变的是对当前状态无效的数据，那么在回溯后就不需要恢复现场
        up[k] = h[u];
        dfs(u + 1, su + 1, sd);
    }

    k = 0;
    while (k < sd && down[k] <= h[u]) k++;
    if (k < sd) {
        int t = down[k];
        down[k] = h[u];
        dfs(u + 1, su, sd);
        down[k] = t;
    } else {
        down[k] = h[u];
        dfs(u + 1, su, sd + 1);
    }
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) cin >> h[i];

        ans = n;
        dfs(0, 0, 0);

        cout << ans << endl;
    }

    return 0;
}