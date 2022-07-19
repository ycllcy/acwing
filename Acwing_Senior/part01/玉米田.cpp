#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 13, M = 1 << N, mod = 1e8;

int n, m;
int g[N];
int f[N][M];
vector<int> state;
vector<int> head[M];

bool check(int state) {
    for (int i = 0; i < m; i++) {
        if ((state >> i & 1) && (state >> (i + 1) & 1))
            return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            int t;
            scanf("%d", &t);

            g[i] += !t << j;
        }

    for (int i = 0; i < 1 << m; i++)
        if (check(i))
            state.push_back(i);
    
    
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];

            if ((a & b) == 0)
                head[i].push_back(j);
        }

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < state.size(); j++) 
            if ((state[j] & g[i]) == 0) 
                for (int k : head[j]) {
                    // 这里不需要在判断第i-1行的状态是否合法，因为在遍历第i-1行时已经判断过了
                    // 如果第i-1行的状态不合法，那么对应的f[i-1][k]则为0
                    f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                }

    int res = 0;
    for (int i = 0; i < state.size(); i++) res = (res + f[n][i]) % mod;
    printf("%d", res);

    return 0;
}