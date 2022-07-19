#include <iostream>

using namespace std;

const int N = 200010;

int n, m;
int w[N], q[N], f[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) {
        if (q[hh] < i - m) hh++;
        f[i] = f[q[hh]] + w[i];
        while (hh <= tt && f[q[tt]] >= f[i]) tt--;
        q[++tt] = i;
    }

    int res = 1e9;
    // 这里枚举最后一个点所有可能的位置
    for (int i = n - m + 1; i <= n; i++) res = min(res, f[i]);

    printf("%d", res);

    return 0;
}