#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 55, M = 35, INF = 1e9;

int n;
int w[N];
int f[N][N][M];

void add(int a[], int b[]) {
    static int c[M];
    memset(c, 0, sizeof c);
    int t = 0;
    for (int i = 0; i < M; i++) {
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}

void mul(int a[], int b) {
    static int c[M];
    memset(c, 0, sizeof c);
    long long t = 0;
    for (int i = 0; i < M; i++) {
        t += (long long) a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}

int cmp(int a[], int b[]) {
    for (int i = M - 1; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    return 0;
}

void print(int a[]) {
    int k = M - 1;
    while (k && !a[k]) k--;
    while (k >= 0) cout << a[k--];
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];

    int temp[M];
    for (int len = 3; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            f[l][r][M - 1] = 1;
            for (int k = l + 1; k < r; k++) {
                memset(temp, 0, sizeof temp);
                // 这里偷了个懒，全部放在第1位了。在后面的mul()函数中我们会将第一位上存的数逐位展开，所以对结果没有影响。
                // 所以我偷偷地在mul()函数是这么定义的：LL t = 0;，和add()函数不同。
                temp[0] = w[l];
                mul(temp, w[k]);
                mul(temp, w[r]);
                add(temp, f[l][k]);
                add(temp, f[k][r]);
                if (cmp(f[l][r], temp) > 0) 
                    memcpy(f[l][r], temp, sizeof temp);
            }
        }
    }

    print(f[1][n]);

    return 0;
}