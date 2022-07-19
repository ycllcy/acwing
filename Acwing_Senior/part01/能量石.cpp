#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110, M = 10010;

struct Stone {
    int s, e, l;

    bool operator < (const Stone& w) const {
        return s * w.l < w.s * l;
    }
} stone[N];

int T, n;
int f[M];

int main() {
    scanf("%d", &T);

    for (int C = 1; C <= T; C++) {
        /*
        对于含有多组测试数据的题目，在处理每一组测试数据时一定要注意数据舒适化的问题
        */
        memset(f, -0x3f, sizeof f);
        f[0] = 0;
        /*
        对于动态规划问题中的状态表示中的集合，可以根据题目需要决定将集合表示为“不超过”还是“恰好是”
        对于不同的集合表示，只要状态转移方程没有问题，就是都可以得出正确结果的，只是不同的集合表示可能在难度上有区别
        同时对于背包问题中的“体积”，有时题目并未明确指出，需要自己判断并计算体积
        */
        int m = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &stone[i].s, &stone[i].e, &stone[i].l);
            m += stone[i].s;
        }
        sort(stone, stone + n);


        for (int i = 0; i < n; i++) {
            for (int j = m; j >= stone[i].s; j--)
                f[j] = max(f[j], f[j - stone[i].s] + stone[i].e - (j - stone[i].s) * stone[i].l);
        }

        int res = 0;
        for (int i = 0; i <= m; i++) res = max(res, f[i]);

        printf("Case #%d: %d\n", C, res);
    }

    return 0;
}