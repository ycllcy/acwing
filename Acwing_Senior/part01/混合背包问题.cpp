#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int n, m;
int f[N], g[N], q[N];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        int v, w, s;
        scanf("%d%d%d", &v, &w, &s);

        if (s == 0) {
            for (int j = v; j <= m; j++)
                f[j] = max(f[j], f[j - v] + w);
        } else {
            if (s == -1) s = 1;

            // 以余数作为分组
            for (int j = 0; j < v; j++) {
                int hh = 0, tt = -1;
                memcpy(g, f, sizeof f);
                for(int k = j; k <= m; k += v) {
                    if (hh <= tt && q[hh] < k - s * v) hh++;
                    while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt--;
                    q[++tt] = k;
                    f[k] = g[q[hh]] + (k - q[hh]) / v * w;
                }
            }
        }
    }

    printf("%d", f[m]);

    return 0;
}