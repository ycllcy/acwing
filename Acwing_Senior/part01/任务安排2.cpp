#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 300010;

int n, s;
int t[N], c[N];
int f[N];
int q[N];

int main() {
    scanf("%d%d", &n, &s);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t[i], &c[i]);
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }

    f[0] = 0;
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) {
        while (hh < tt && (f[q[hh + 1]] - f[q[hh]]) <= (c[q[hh + 1]] - c[q[hh]]) * (t[i] + s)) hh++;
        int j = q[hh];
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];
        while (hh < tt && (f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt - 1]]) >= (c[q[tt]] - c[q[tt - 1]]) * (f[i] - f[q[tt - 1]])) tt--;
        q[++tt] = i;
    }

    printf("%d", f[n]);

    return 0;
}