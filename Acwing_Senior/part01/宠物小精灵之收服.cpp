#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 510;

int n, m, k;
int f[N][M];

int main() {
    scanf("%d%d%d", &m, &k, &n);

    for (int i = 0; i < n; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);

        for (int j = m; j >= v1; j--)
            for (int l = k - 1; l >= v2; l--)
                f[j][l] = max(f[j][l], f[j - v1][l - v2] + 1);
    }

    printf("%d ", f[m][k - 1]);

    int cnt = 0;
    while (cnt < k && f[m][cnt] != f[m][k - 1]) cnt++;
    printf("%d", k - cnt);

    return 0;
}