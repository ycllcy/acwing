#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110, M = 25010;

int n;
int q[N];
int f[M];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &q[i]);
        sort(q, q + n);

        memset(f, 0, sizeof f);
        f[0] = 1;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // 这里无需考虑已经被排除在最终方案之外的面值是否可以用来表示当前q[i]
            // 因为就算表示当前q[i]的面值方案中包含已经被排除在最终方案之外的面值
            // 那么这个被排除的面值一定是可以由他前面的若干面值表示的，也就是说当前q[i]完全可以由最终方案中的若干面值表示
            if (!f[q[i]]) cnt++;
            for (int j = q[i]; j <= q[n - 1]; j++)
                f[j] += f[j - q[i]];
        }

        printf("%d\n", cnt);
    }
    return 0;
}