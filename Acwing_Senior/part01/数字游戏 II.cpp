#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 11, M = 110;

int P;
int f[N][10][M];

int mod(int x, int y) {
    // C++中对一个负数取模得到的值为负数
    // 因此这里需要手写一个取模函数
    // 数学定义：余数只能是正数
    return (x % y + y) % y;
}

void init() {
    memset(f, 0, sizeof f);

    for (int i = 0; i <= 9; i++) f[1][i][i % P]++;

    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k < P; k++)
                for (int x = 0; x <= 9; x++)
                    // 这里一共有i位数，所有位之和的余数为k，那么剩余i-1位的余数就应该是
                    f[i][j][k] += f[i - 1][x][mod(k - j, P)];
}

int dp(int n) {
    if (!n) return 1;

    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];
        for (int j = 0; j < x; j++)
            res += f[i + 1][j][mod(-last, P)];

        last += x;

        if (!i && last % P == 0) res++;
    }
    return res;
}

int main() {
    int l, r;
    while (cin >> l >> r >> P) {
        init();

        cout << dp(r) - dp(l - 1) << endl;
    }

    return 0;
}