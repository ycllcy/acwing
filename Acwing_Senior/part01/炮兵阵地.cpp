#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110, M = 1 << 12;

int n, m;
int g[N], cnt[M];
int f[2][M][M];
// 这里只定义了一个合法状态的vector，没有定义这些合法状态可以由哪些合法状态转移而来的vector
// 因为这里f中包含了第i行和第i-1行的状态，相当于是需要判断第i行和第i-1行的整个的状态，可以由第i-2行的哪些合法状态转移而来
// 如果想要预处理的话需要定义vector<int> head[M][M]，相当于是一个三维数组，比较复杂，因此这里直接在枚举时判断
vector<int> state;

int count(int state) {
    int res = 0;
    for (int i = 0; i < m; i++)
        res += state >> i & 1;
    return res;
}

bool check(int state) {
    for (int i = 0; i < m; i++)
        if ((state >> i & 1) && ((state >> (i + 1) & 1) || (state >> (i + 2) & 1)))
            return false;
    return true;
}

int main() {
    cin >> n >> m;

    /*
    使用cin读入单个字符会忽略空格
    使用scanf读入单个字符不会忽略空格
    */
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'H') g[i] += 1 << j;
        }
    }

    for (int i = 0; i < 1 << m; i++) {
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }
    }

    for (int i = 1; i <= n + 2; i++) 
        for (int j = 0; j < state.size(); j++)
            for (int k = 0; k < state.size(); k++)
                for (int u = 0; u < state.size(); u++) {
                    int a = state[j], b = state[k], c = state[u];

                    if ((g[i] & a) | (g[i - 1] & b)) continue;
                    if ((a & b) | (b & c) | (a & c)) continue;
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[(i - 1) & 1][k][u] + cnt[a]);
                }

    cout << f[n + 2 & 1][0][0] << endl;

    return 0;
}