#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3010;

int n;
int a[N], b[N];
int f[N][N];

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1; i <= n; i++) scanf("%d",&b[i]);

    // f[i][j]表示以第一个序列的前i个数字和第二个序列的前j个数字构成且以第二个序列的第j个数字结尾的公共上升子序列
    for (int i = 1; i <= n; i++) {
        int maxv = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = max(f[i][j], f[i - 1][j]);

            if (a[i] == b[j]) {
                // int maxv = 1;
                // for (int k = 1; k < j; k++)
                //     if (b[k] < a[i]) maxv = max(maxv, f[i - 1][k] + 1);
                f[i][j] = max(f[i][j], maxv);
            }
            if (b[j] < a[i]) maxv = max(maxv, f[i - 1][j] + 1);
        }
    }


    int res = 0;
    for (int i = 0; i <= n; i++) res = max(res, f[n][i]);

    printf("%d", res);

    return 0;
}