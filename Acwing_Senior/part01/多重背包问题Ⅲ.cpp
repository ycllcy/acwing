#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20010;

int n, m;
int f[N], g[N], q[N];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        int v, w, s;
        scanf("%d%d%d", &v, &w, &s);
        memcpy(g, f, sizeof f);

        for (int j = 0; j < v; j++) {
            int hh = 0, tt = -1;
            // 通过余数对j进行分组后，每个不同的余数是一组
            // 然后从小到大遍历每组中不同的体积
            // 这里遍历k就相当于遍历f[i][j]的第二维
            for (int k = j; k <= m; k += v) {
                if (hh <= tt && q[hh] < k - s * v) hh++;
                // 这里比较的是相对大小，而不是绝对大小，因此可以直接-(q[tt] - j) / v * w 
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt--;
                q[++tt] = k;
                // 最大的数的下标为q[hh]，然后再在f[i - 1][q[hh]]的基础上加上若干个w(k - q[hh] / v * w)
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }

    printf("%d", f[m]);

    return 0;
}