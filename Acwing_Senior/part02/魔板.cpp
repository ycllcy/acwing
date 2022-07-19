#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

char g[2][4];
unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;

void set(string state) {
    for (int i = 0; i < 4; i++) g[0][i] = state[i];
    for (int i = 7, j = 0; i > 3; i--, j++) g[1][j] = state[i];
}

string get() {
    string state;
    // 注意：在C++中不能使用+拼接字符串数组
    //state += g[0];
    for (int i = 0; i < 4; i++) state += g[0][i];
    for (int i = 3; i >= 0; i--) state += g[1][i];
    return state;
}

string move0(string state) {
    set(state);
    swap(g[0], g[1]);
    //for (int i = 0; i < 4; i++) swap(g[0][i], g[1][i]);
    return get();
}

string move1(string state) {
    set(state);
    int v0 = g[0][3], v1 = g[1][3];
    for (int i = 3; i > 0; i--) g[0][i] = g[0][i - 1], g[1][i] = g[1][i - 1];
    g[0][0] = v0;
    g[1][0] = v1;
    return get();
}

string move2(string state) {
    set(state);
    int v = g[0][2];
    g[0][2] = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = v;
    return get();
}

int bfs(string start, string end) {
    if (start == end) return 0;

    queue<string> q;
    q.push(start);
    dist[start] = 0;

    while (q.size()) {
        string t = q.front(); q.pop();

        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);

        for (int i = 0; i < 3; i++) {
            if (!dist[m[i]]) {
                q.push(m[i]);
                dist[m[i]] = dist[t] + 1;
                pre[m[i]] = {'A' + i, t};
                if (m[i] == end) return dist[m[i]];
            }
        }
    }

    return -1;
}

int main() {
    int x;
    string end, start;
    for (int i = 0; i < 8; i++) {
        cin >> x;
        end += char (x + '0');
        start += char (i + '1');
    }

    int step = bfs(start, end);

    cout << step << endl;

    
    if (step > 0) {
        string res;
        while (end != start) {
            res += pre[end].first;
            end = pre[end].second;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }

    return 0;
}