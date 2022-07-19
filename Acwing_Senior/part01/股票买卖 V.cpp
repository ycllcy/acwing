#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int f[3];

int main() {
    scanf("%d", &n);

    // 初始化
    f[0] = f[1] = -0x3f3f3f3f;
    f[2] = 0;

    for (int i = 1; i <= n; i++) {
        int w;
        scanf("%d", &w);
        int a = f[0], b = f[1], c = f[2];
        f[0] = max(f[0], f[2] - w);
        f[1] = a + w;
        f[2] = max(c, b);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = max(f[1], f[2]);

    printf("%d", res);

    return 0;
}