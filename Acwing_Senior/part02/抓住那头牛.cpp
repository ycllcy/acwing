#include <iostream>
#include <cstring>

using namespace std;

const int N = 200010;

int n, k;
int q[N];
int dist[N];

int bfs() {
    memset(dist, -1, sizeof dist);

    int hh = 0, tt = 0;
    q[0] = n;
    dist[n] = 0;

    while (hh <= tt) {
        int t = q[hh++];

        if (t == k) return dist[t];

        if (t - 1 >= 0 && dist[t - 1] == -1) {
            q[++tt] = t - 1;
            dist[t - 1] = dist[t] + 1;
        }
        if (t + 1 <= k && dist[t + 1] == -1) {
            q[++tt] = t + 1;
            dist[t + 1] = dist[t] + 1;
        }
        // if (t * 2 < k * 2 && dist[t * 2] != -1)
        if (t < k && dist[t * 2] == -1) {
            q[++tt] = t * 2;
            dist[t * 2] = dist[t] + 1;
        }
    }

    return -1;
}

int main() {
    cin >> n >> k;

    cout << bfs() << endl;

    return 0;
}