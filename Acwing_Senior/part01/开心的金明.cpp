#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30010;

int n, m;
int f[N];

int main() {
    scanf("%d%d", &m, &n);

    while (n--) {
        int v, w;
        scanf("%d%d", &v, &w);
        w *= v;

        for (int j = m; j >= v; j--)
            f[j] = max(f[j], f[j - v] + w);
    }

    printf("%d", f[m]);

    return 0;
}