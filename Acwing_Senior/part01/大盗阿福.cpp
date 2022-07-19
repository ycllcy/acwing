#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int n;
int f[2];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        f[0] = 0, f[1] = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            int w;
            scanf("%d", &w);
            int a = f[0], b = f[1];

            f[0] = max(a, b);
            f[1] = a + w;
        }

        printf("%d\n", max(f[0], f[1]));
    }

    return 0;
}