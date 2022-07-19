#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3010;

int n, m;
long long f[N];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        f[0] = 1;
        int v;
        cin >> v;
        for (int j = v; j <= m; j++)
            f[j] += f[j - v];
    }

    printf("%lld", f[m]);

    return 0;
}