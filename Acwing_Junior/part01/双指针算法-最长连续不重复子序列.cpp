#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], cnt[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

    int res = 0;
    for (int i = 0, j = 0; j <= n - 1; j ++) {
        ++ cnt[q[j]];
        while (i < j && cnt[q[j]] > 1) --cnt[q[i++]];
        res = max(res, j - i + 1);
    }

    printf("%d", res);

    return 0;
}