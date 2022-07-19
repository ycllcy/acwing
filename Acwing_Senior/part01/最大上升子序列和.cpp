#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int q[N];
int f[N];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &q[i]);

    for (int i = 1; i <= n; i++) {
        f[i] = q[i];
        for (int j = 1; j < i; j++)
            if (q[j] < q[i]) f[i] = max(f[i], f[j] + q[i]);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[i]);

    printf("%d", res);

    return 0;
}