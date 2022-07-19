#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int K, n;
int h[N];
int f[N], g[N];

int main() {
    scanf("%d", &K);

    while (K--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &h[i]);

        for (int i = 1; i <= n; i++) {
            f[i] = 1;
            for (int j = 1; j <= i; j++)
                if (h[i] > h[j]) f[i] = max(f[i], f[j] + 1);
        }

        for (int i = n; i >= 1; i--) {
            g[i] = 1;
            for (int j = n; j >= i; j--)
                if (h[i] > h[j]) g[i] = max(g[i], g[j] + 1);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, f[i]);
            res = max(res, g[i]);
        }
        
        printf("%d\n", res);
    }
    return 0;
}
