#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 110;

int n, m;
int f[N][M][2];

int main() {
    scanf("%d%d", &n, &m);
    
    // 如果状态转移方程中第i状态的确定只是用到了i-1的状态，那么在初始化时只需初始化f[0]
    // 不需要使用memset初始化所有状态
    // memset(f, -0x3f, sizeof f);
    // 这么说也不严谨，比如在这个题中，f[i][j][1]的确定需要用到f[i - 1][j - 1][0]
    // 所以j必须从1开始循环，因此必须对j=0进行初始化，由于在整个遍历过程中，f[i][0][0]不会根据上一个状态进行更新
    // 因此需要对所有f[i][0][0]进行初始化，而由于静态数组本身就是0，所以这里省略了这一初始化过程
    // 总的来说，初始化要根据状态转移方程的具体情况（这里指从哪一维开始循环能使状态转移方程合法（数组不越界））以及含义（这里指初始化时初始化为0还是无穷）来定
    for (int i = 0; i <= m; i++) f[0][i][0] = f[0][i][1] = -0x3f3f3f3f;
    f[0][0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int w;
        scanf("%d", &w);
        for (int j = 1; j <= m; j++) {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w);
            f[i][j][1] = max(f[i - 1][j - 1][0] - w, f[i - 1][j][1]);
        }
    }
    
    int res = 0;
    for (int i = 1; i <= m; i++) res = max(res, f[n][i][0]);

    printf("%d", res);

    return 0;
}