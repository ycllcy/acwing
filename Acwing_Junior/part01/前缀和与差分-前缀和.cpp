#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int s[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }

    int l, r;
    while (m --) {
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}