#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<double, double> PDD;

const int N = 18, M = 1 << N;
const double eps = 1e-6;

int n, m;
PDD q[N];
int path[N][N];
int f[M];

int cmp(double a, double b) {
    if (fabs(a - b) < eps) return 0;
    if (a < b) return -1;
    return 1;
}
/*
首先明确基本的重复覆盖问题是什么样的，就是给定一个01矩阵，选择尽量少的行，使所有列都能被覆盖到
这里的path就是作为可以选择的行，因为path中存储了某一条二次曲线可以覆盖到哪些点
而消灭所有猪就相当于使所有列都被覆盖到
最少使用多少个小鸟就是选择尽量少的行，使所有列都被覆盖到
而重复覆盖问题的一个做法就是每次选择任意没有被覆盖的列，然后枚举可以覆盖这一列的行
*/
int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> q[i].x >> q[i].y;

        memset(path, 0, sizeof path);
        for (int i = 0; i < n; i++) {
            path[i][i] = 1 << i;
            for (int j = 0; j < n; j++) {
                double x1 = q[i].x, y1 = q[i].y;
                double x2 = q[j].x, y2 = q[j].y;
                if (!cmp(x1, x2)) continue;
                double a = (y1 / x1 - y2 / x2) / (x2  -x2);
                double b = y1 / x1 - a * x1;
                if (cmp(a, 0.0) != -1) continue;
                int state = 0;
                for (int k = 0; k < n; k++) {
                    double x = q[k].x, y = q[k].y;
                    if (!cmp(a * x * x + b * x, y)) state += 1 << k;
                }
                path[i][j] = state;
            }
        }

        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        // 这里枚举到1 << n - 2即可，因为在枚举1 << n - 2时还有一列没有被覆盖，在循环内部会找到这一列并进行覆盖
        for (int i = 0; i < 1 << n - 1; i++) {
            int x = 0;
            for (int j = 0; j < n; j++) {
                if (!(i << j & 1)) {
                    x = j;
                    break;
                }
            }

            for (int j = 0; j < n; j++)
                f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
        }
        cout << f[(1 << n) - 1] << endl;
    }

    return 0;
}