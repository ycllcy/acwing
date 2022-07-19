#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int q[N], temp[N];

LL merge_sort(int q[], int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) >> 1;
    LL cnt = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int k = 0;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) temp[k ++] = q[i ++];
        else {
            cnt += mid - i + 1;
            temp[k ++] = q[j ++];
        }
    }

    while (i <= mid) temp[k ++] = q[i ++];
    while (j <= r) temp[k ++] = q[j ++];

    for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = temp[j];
    
    return cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    printf("%lld", merge_sort(q, 0, n - 1));

    return 0;
}