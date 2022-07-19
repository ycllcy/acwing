#include <iostream>
#include <algorithm>

using namespace std;

const int N = 35;

int n;
int w[N];
int f[N][N], g[N][N];

void dfs(int l, int r) {
    if (l > r) return;

    cout << g[l][r] << " ";
    dfs(l, g[l][r] - 1);
    dfs(g[l][r] + 1, r);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> w[i];

    for (int len = 1; len <= n; len++) 
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;

            if (len == 1) f[l][r] = w[l], g[l][r] = l;
            else {
                for (int k = l; k <= r; k++) {
                    int left = (k == l) ? 1 : f[l][k - 1];
                    int right = (k == r) ? 1 : f[k + 1][r];
                    int score = left * right + w[k];
                    // 由于需要输出字典序最小的方案，而先序遍历会优先输出根节点
                    // 因此在记录根节点时，只有当f[l][r]严格小于score时再更新根节点
                    if (f[l][r] < score) {
                        f[l][r] = score;
                        g[l][r] = k;
                    }
                }
            }
        }
    
    cout << f[1][n] << endl;

    dfs(1, n);

    return 0;
}