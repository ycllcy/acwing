#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11010, M = 2010;

int n, m;
int v[N], w[N];
int f[M];

int main() {
    scanf("%d%d", &n, &m);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b, s;
        scanf("%d%d%d", &a, &b, &s);

        int k = 1;
        while (k <= s) {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if (s) {
            cnt ++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    for (int i = 1; i <= cnt; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    printf("%d", f[m]);

    return 0;
}