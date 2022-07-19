#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100010, M = 100010, P = 110;

int n, m, p;
LL d[N], t[N];
LL a[N], s[N];
LL f[P][M];
int q[N];

LL get_y(int i, int k) {
    return f[i - 1][k] + s[k];
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 2; i <= n; i++) {
        scanf("%lld", &d[i]);
        d[i] += d[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        int h;
        scanf("%d%lld", &h, &t[i]);
        a[i] = t[i] - d[h];
    }

    // 我们在对小猫分组时一定是让出发时间相近的尽量在一组
    // 对每只小猫最早去接的时间从小到大排序（对于每一组最早的出发时间就是当前组中所有小猫中最晚的那个）
    sort(a + 1, a + m + 1);

    for (int i = 1; i <= m; i++) s[i] = a[i] + s[i - 1];
    
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= p; i++) f[i][0] = 0;
    
    for (int i = 1; i <= p; i++) {
        int hh = 0, tt  =0;

        for (int j = 1; j <= m; j++) {
            while (hh < tt && (get_y(i, q[hh + 1]) - get_y(i, q[hh]) <= 
                        (a[j]) * (q[hh + 1] - q[hh]))) hh++;
            int k = q[hh];
            f[i][j] = f[i - 1][k] + (j - k) * a[j] - (s[j] - s[k]);
            while (hh < tt && (get_y(i, q[tt] - get_y(q[tt - 1], i))) * (j - q[tt]) >= 
                                (q[tt] - q[tt - 1]) * (get_y(i, j) - get_y(i, q[tt]))) tt--;
            q[++tt] = j;
        }
    }

    printf("%lld", f[p][m]);

    return 0;
}