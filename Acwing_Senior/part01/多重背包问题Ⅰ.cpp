#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int f[N];

int main() {
    scanf("%d%d", &n, &m);
    // 在背包问题的一维数组优化中，只有完全背包和多重背包的单调队列优化是正序循环，其他一维优化都是逆序循环
    for (int i = 0;  i < n; i++) {
        int s, w, v;
        scanf("%d%d%d", &v, &w, &s);
        for (int j = m; j > 0; j--)
            for (int k = 0; k <= s; k++)
                if (j >= k * v)
                    f[j] = max(f[j], f[j - k * v] + k * w);
    }

    printf("%d", f[m]);

    return 0;
}