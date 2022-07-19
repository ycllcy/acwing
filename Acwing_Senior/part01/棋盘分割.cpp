#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 15, M = 9;
const double INF = 1e9;

int n, m = 8;
int s[M][M];
double f[M][M][M][M][N];
double X;

double get(int x1, int y1, int x2, int y2) {
    double sum = (double) s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] - X;
    return sum * sum;
}

double dp(int x1, int y1, int x2, int y2, int k) {
    double &v = f[x1][y1][x2][y2][k];
    if (v >= 0) return v;
    if (k == 1) return v = get(x1, y1, x2, y2);

    v = INF;
    for (int i = x1; i < x2; i++) {
        v = min(v, dp(x1, y1, i, y2, k - 1) + get(i + 1, y1, x2, y2));
        v = min(v, dp(i + 1, y1, x2, y2, k - 1) + get(x1, y1, i, y2));
    }

    for (int i = y1; i < y2; i++) {
        v = min(v, dp(x1, y1, x2, i, k - 1) + get(x1, i + 1, x2, y2));
        v = min(v, dp(x1, i + 1, x2, y2, k - 1) + get(x1, y1, x2, i));
    }

    return v;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &s[i][j]);
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }

    X = (double) s[m][m] / n;
    // f是有可能等于0的
    memset(f, -1, sizeof f);
    printf("%.3lf", sqrt((double) dp(1, 1, m, m, n) / n));

    return 0;
}