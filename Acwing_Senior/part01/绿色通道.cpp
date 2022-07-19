#include <iostream>

using namespace std;

const int N = 50010;

int n, t;
int w[N], q[N], f[N];

bool check(int limit) {
    int hh = 0, tt = 0;

    for (int i = 1; i <= n; i++) {
        if (q[hh] < i - limit - 1) hh++;
        f[i] = f[q[hh]] + w[i];
        while (hh <= tt && f[q[tt]] >= f[i]) tt--;
        q[++tt] = i;
    }

    for (int i = n - limit; i <= n; i++)
        if (f[i] <= t)
            return true;
    return false;
}

int main() {
    scanf("%d%d", &n, &t);

    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    int l = 0, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d", r);

    return 0;
}