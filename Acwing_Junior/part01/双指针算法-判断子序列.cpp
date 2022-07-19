#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    bool flag = false;
    for (int i = 0, j = 0; i < m; i ++) {
        if (j < n && a[j] == b[i]) j ++;
        if (j == n) {
            flag = true;
        }
    }

    printf("%s", flag ? "Yes" : "No");

    return 0;
}