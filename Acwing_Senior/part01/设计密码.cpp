#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int  N = 55, mod = 1e9 + 7;

int n;
char t[N];
int ne[N];
int f[N][N];

int main() {
    scanf("%d", &n);
    scanf("%s", t + 1);
    int len = strlen(t + 1);

    for (int i = 2, j = 0; i <= len; i++) {
        while (j && t[i] != t[j + 1]) j = ne[j];
        if (t[i] == t[j + 1]) j++;
        ne[i] = j;
    }

    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            for (int k = 'a'; k <= 'z'; k++) {
                int u = j;

                while (u && k != t[u + 1]) u = ne[u];
                if (k == t[u + 1]) u++;
                if (u < len) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
            }
        }
    }


    int res = 0;
    for (int i = 0 ; i < len; i++) res = (res + f[n][i]) % mod; 
    printf("%d", res);

    return 0;
}