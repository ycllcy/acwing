#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int q[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", & q[i]);

    while (m --) {
        int k;
        scanf("%d", &k);

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (q[mid] < k) l = mid + 1;
            else r = mid;
        }
        if (q[l] != k) puts("-1 -1");
        else {
            printf("%d ", l);
            l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= k) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", l);
        }
    }
    
    return 0;
}