#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &s[i]);
        a[i] = s[i] - s[i - 1];
    }

    int l, r, c;
    while (m --) {
        scanf("%d%d%d", &l, &r, &c);
        a[l] += c;
        a[r + 1] -= c; 
    }

    for (int i = 1; i <= n; i++) {
        s[i] = a[i] + s[i - 1];
        printf("%d ", s[i]);
    }

    return 0;
}