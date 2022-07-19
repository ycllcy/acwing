#include <iostream>

using namespace std;

const int N = 1010;

int m;
int f[N];
int v[4] = {10, 20, 50, 100};

int main() {
    scanf("%d", &m);

    for (int i = 0; i < 4; i++) {
        f[0] = 1;
        for (int j = v[i]; j <= m; j++)
            f[j] += f[j - v[i]];
    }

    printf("%d", f[m]);

    return 0;
}