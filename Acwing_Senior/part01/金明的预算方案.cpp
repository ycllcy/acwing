#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int  N = 32010, M = 65;

int n, m;
int f[N];
PII primary[M];
vector<PII> secondary[M];

int main() {
    scanf("%d%d", &m, &n);

    for (int i = 1; i <= n; i++) {
        int v, w, q;
        scanf("%d%d%d", &v, &w, &q);
        w = v * w;
        if (!q) primary[i] = {v, w};
        else secondary[q].push_back({v, w});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            // 当需要枚举每种方案时，可以使用二进制优化
            for (int u = 0; u < (1 << secondary[i].size()); u++) {
                int v = primary[i].first, w = primary[i].second;
                for (int k = 0; k < secondary[i].size(); k++) {
                    if (u >> k & 1) {
                        v += secondary[i][k].first;
                        w += secondary[i][k].second;
                    }
                }
                if (j >= v) f[j] = max(f[j], f[j - v] + w);
            }
        }
    }

    printf("%d", f[m]);

    return 0;
}