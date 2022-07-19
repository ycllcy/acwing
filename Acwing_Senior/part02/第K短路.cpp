/*
首先，由于我们需要求第k短路，那么在扩展一个点时就不能只把满足三角不等式的点扩展进来
要把一个点所有能扩展的点都加入到队列中
由于A-star算法中终点第一次出队是第一短路，那我们猜想：第k次出队是不是第k短路呢？
假设终点第2次出队不是第2短路，那么这个距离一定严格大于第2短路，由于我们在队列中存的是一个点到起点的实际距离+这个点到终点的估计距离
所以第二短路上的点在优先队列中存储的值一定是小于等于第二短路的实际距离的，也就小于我们这里假设的终点第2次出队的这个距离，因此假设不成立
*/
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int N = 1010, M = 20010;

int n ,m;
int S, T, K;
int h[N], rh[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int h[], int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

void dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, T});

    memset(dist, 0x3f, sizeof dist);
    dist[T] = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.y;
        if (st[ver]) continue;
        st[ver] = true;

        for (int i = rh[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            } 
        }
    }
}

int astar() {
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    heap.push({dist[S], {0, S}});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.y.y, d = t.y.x;
        cnt[ver]++;
        if (cnt[T] == K) return d;

        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (cnt[j] < K)
                heap.push({d + w[i] + dist[j], {d + w[i], j}});
        }
    }

    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    scanf("%d%d%d", &S, &T, &K);
    if (S == T) K++;

    dijkstra();

    printf("%d", astar());

    return 0;
}