#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10010;

int n, m;
int f[N];

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        f[0] = 1;
        int v;
        scanf("%d", &v);

        for (int j = m; j >= v; j--)
            f[j] += f[j - v];
    }

    printf("%d", f[m]);

    return 0;
}