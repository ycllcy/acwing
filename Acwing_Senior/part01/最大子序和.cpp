#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 300010;

int n, m;
int q[N], s[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }

    int res = -0x3f3f3f3f;
    // 因为求前缀和可能需要用到s[0]。
    // 例如如果我们只选第一个数，那么就是s[1]-s[0]，因此需要将s[0]也加入单调队列中，所以这里tt=0，也就是默认加入一个s[0]了。
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) {
        // 因为这里要用到前缀和，要去找使得长度不超过m的区间和，当长度取m时，要用到s[k - m]，因为此这里要包括往前数第m+1个数
        if (hh <= tt && q[hh] < i - m) hh++;
        // 因为要选择第i个数的前m个数的前缀和的最小值，因此需要在更新队列前更新res的值
        res = max(res, s[i] - s[q[hh]]);
        while (hh <= tt && s[q[tt]] >= s[i]) tt--;
        q[++tt] = i;
        
    }

    printf("%d", res);

    return 0;
}