#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m, w;
int f[N][N];

int main() {
    scanf("%d%d%d", &n, &m, &w);

    while (n--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        for (int j = m; j >= a; j--)
            for (int k = w; k >= b; k--)
                f[j][k] = max(f[j][k], f[j - a][k - b] + c);
    }

    printf("%d", f[m][w]);

    return 0;
}