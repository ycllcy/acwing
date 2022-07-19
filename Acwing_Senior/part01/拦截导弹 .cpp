#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int f[N], h[N], q[N];

int main() {
    while (cin >> h[n]) {
        n++;
    }

    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (h[j] >= h[i]) f[i] = max(f[i], f[j] + 1);
    }

    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, f[i]);
    cout << res << endl;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // 这里不能使用二分查找，虽然q数组是有序的，但是在q数组中可能不存在大于等于h[i]的数
        int k = 0;
        while (k < cnt && q[k] < h[i]) k++;
        q[k] = h[i];
        if (k == cnt) cnt++;
    }

    cout << res << endl;
    cout << cnt << endl;

    return 0;
}