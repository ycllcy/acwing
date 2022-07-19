#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 11, K = 110, M = 1 << N;

int n, m;
long long f[N][K][M];
vector<int> state;
vector<int> head[M];
int cnt[M];

bool check(int state) {
    for (int i = 0; i < n; i++) {
        if ((state >> i & 1) && (state >> (i + 1) & 1)) {
            return false;
        }
    }

    return true;
}

int count(int state) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += state >> i & 1;
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < 1 << n; i++) {
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }
    }

    for (int i = 0; i < state.size(); i++) {
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];

            if ((a & b) == 0 && check(a | b)) 
                head[i].push_back(j);
        }
    }

    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= m; j++) 
            for(int a = 0; a < state.size(); a++) 
                for (int b : head[a]) {
                // for (int b = 0; b < head[a].size(); b++)
                    int c = cnt[state[a]];

                    if (j >= c)
                        // f[i][j][a] += f[i - 1][j - c][head[a][b]];
                        f[i][j][a] += f[i - 1][j - c][b];
                }

    long long res = 0;
    for (int i = 0; i < 1 << n; i++) res += f[n][m][i];
    printf("%lld", res);

    return 0;
}