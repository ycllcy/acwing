#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], f[N][N];
int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u) {
    // 初始化f，因为选u，所以体积必须大于v[u]
    for (int i = v[u]; i <= m; i++)
        f[u][i] = w[u];

    // 将有依赖的背包问题转化为分组背包问题
    // 对于以u为根节点的子树，从前i个背包（u的子树）中选，且体积不超过j的所有方案
    // 对于以u为根节点的子树，f[u][i][j]相当于分组背包中的f[i][j]
    for (int i = h[u]; ~i; i = ne[i]) { // 把u的所有子节点看做分组背包，遍历所有背包（物品）
        int son = e[i];
        dfs(son);
        
        // 这里因为已经选上u了，所以最大体积是从m开始，对于另一种写法，一开始没有选上u，所以最大体积从m - v[u]开始
        for (int j = m; j >= v[u]; j--) {   // 遍历体积，这里是优化过一维的，因此体积要逆序
            for (int k = 0; k <= j - v[u]; k++) // 决策

                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    int root;
    for (int i = 1; i <= n; i++) {
        int p;
        scanf("%d%d%d", &v[i], &w[i], &p);
        if (p == -1) root = i;
        else add(p, i);
    }

    dfs(root);

    printf("%d", f[root][m]);

    return 0;
}