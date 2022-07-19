#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n, m;
int f[N], g[N];

int main() {
    scanf("%d%d", &n, &m);

    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;

    for (int i = 0; i < n; i++) {
        int v, w;
        scanf("%d%d", &v, &w);

        for (int j = m; j >= v; j--) {
             int cnt = 0;
             int maxv = max(f[j], f[j - v] + w);
             if (maxv == f[j]) cnt = g[j];
             if (maxv == f[j - v] + w) cnt = (cnt + g[j - v]) % mod;
             f[j] = maxv;
             g[j] = cnt;
        }
    }

    int res = 0;
    for (int i = 1; i <= m; i++) res = max(res, f[i]);

    int cnt = 0;
    for (int i = 0; i <= m; i++)
        if (f[i] == res)
            cnt = (cnt + g[i]) % mod;

    printf("%d", cnt);

    return 0;
}