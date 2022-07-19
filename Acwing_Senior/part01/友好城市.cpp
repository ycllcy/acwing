/*
最长上升子序列的最基础的模型是比较值的大小，
但是题目经过变形以后还可以通过比较一些非数值型的关系得到某些性质的最长子序列
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;

int n;
PII city[N];
int f[N];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d%d", &city[i].first, &city[i].second);
    sort(city, city + n);

    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j <= i; j++)
            if (city[i].second > city[j].second) f[i] = max(f[i], f[j] + 1);
    }

    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, f[i]);

    printf("%d", res);

    return 0;
}