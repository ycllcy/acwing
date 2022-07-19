#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int f[N][N];
int v[N], w[N];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);

    /*
    首先，最优方案可能不止一个，我们对于方案的输出方法是：
    对于f[n][m]判断它是否是由f[n - 1][m - v] + w转换而来，
    即判断f[n][m]是否等于f[n - 1][m - v] + w
    如果相等，说明f[n][m]由f[n - 1][m - v] + w转换而来，进而说明最优方案选择了第n个物品，
    然后根据上面的步骤依次往前推，得到最优方案
    然而题目要求我们输出字典序最小的最优方案，因此需要从第一个物品开始判断，进行与上面类似的步骤，
    从而的到字典序最小的最优方案
    */
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i + 1][j];

            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }  
    }

    int j = m;
    for (int i = 1; i <= n; i++) {
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i]) {
            printf("%d ", i);
            j -= v[i];
        }
    }

    return 0;
}