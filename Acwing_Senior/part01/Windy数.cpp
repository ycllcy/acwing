#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int  N = 11;

int f[N][10];

void init() {
    // 这里需要将一共有1位，值为0看做一种方案，因为还需要这种情况去更新位数比它高的情况
    for (int i = 0; i <= 9; i++) f[1][i] = 1;

    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}

int dp(int n) {
    // 如果这里把0看做一个windy数，那么最后在特判n-1位数时就需要加上一共有一位数，最高位是0这种情况
    // 即for (int j = i != 1; j <= 9; j++)
    if (!n) return 0;

    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = -2;  // 为了能使最高位可以填1~9之间的任意的数，我们将last初始化为-2
    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];

        for (int j = i == nums.size() - 1; j < x; j++)
            if (abs(j - last) >= 2)
                res += f[i + 1][j];
            
        if (abs(x - last) >= 2) last = x;
        else break;

        if (!i) res++;
    }

    for (int i = 1; i < nums.size(); i++)
        for (int j = 1; j <= 9; j++)
            res += f[i][j];
    
    return res;
}

int main() {
    init(); // 预处理

    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l - 1) << endl;

    return 0;
}