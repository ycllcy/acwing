#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 9, M = 1 << N;

// 记录一个状态有多少个1
int ones[M], map[M];
int row[N], col[N], cell[3][3];
char str[100];

void init() {
    for (int i = 0; i < N; i++) row[i] = col[i] = (1 << N)  - 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) 
            cell[i][j] = (1 << N) - 1;
}

void draw(int x, int y, int t, bool is_set) {
    if (is_set) str[x * N + y] = '1' + t;
    else str[x * N + y] = '.';

    // 能放的位置用1表示，不能放的用0来表示
    int v = 1 << t;
    if (!is_set) v = -v;
    
    row[x] -= v;
    col[y] -= v;
    cell[x][y] -= v;
}

int lowbit(int x) {
    return x & -x;
}

int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
    if (!cnt) return true;

    int minv = 10;
    int x, y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (str[i * N + j] == '.') {
                int state = get(i, j);
                if (ones[state] < minv) {
                    minv = ones[state];
                    x = i, y = j;
                }
            }
    
    int state = get(x, y);
    for (int i = state; i; i -= lowbit(i)) {
        int t = map[lowbit(i)];
        draw(x, y, t, true);
        if (dfs(cnt - 1)) return true;
        draw(x, y, t, false);
    }

    return false;
}

int main() {
    for (int i = 0; i < N; i++) map[1 << i] = i;
    for (int i = 0; i < 1 << N; i++)
        for (int j = 0; j < N; j++)
            ones[i] += i >> j & 1;

    while (cin >> str, str[0] != 'e') {
        init();

        int cnt = 0;
        for (int i = 0, k = 0; i < N; i++)
            for (int j = 0; j < N; j++, k++)
                if (str[k] != '.') {
                    int t = str[k] - '1';
                    draw(i, j, t, true);
                }
                else cnt++;
        
        dfs(cnt);

        puts(str);
    }

    return 0;
}