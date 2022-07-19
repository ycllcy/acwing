#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, m;
LL s[N];
LL f[N];
int q[N];

LL g(int i) {
    if (!i) return i;
    return f[i - 1] - s[i];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) {
        if (q[hh] < i - m) hh++;
        f[i] = max(f[i - 1], g(q[hh]) + s[i]);
        while (hh <= tt && g(q[tt]) <= g(i)) tt--;
        q[++tt] = i;
    }

    printf("%lld", f[n]);

    return 0;
}