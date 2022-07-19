#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<int, string> PIS;

int f(string state) {
    int count = 0;
    for (int i = 0; i < state.size(); i++)
        if (state[i] != 'x') {
            int t = state[i] - '1';
            count += abs(t / 3 - i / 3) + abs(t % 3 - i % 3);
        }
    return count;
}

string bfs(string start) {
    string end = "12345678x";
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    char op[] = "urdl";

    unordered_map<string, int> dist;
    unordered_map<string, pair<char, string>> prev;
    priority_queue<PIS, vector<PIS>, greater<PIS>> heap;

    dist[start] = 0;
    // 我们往堆中放的是到起点的实际距离加上这个点到终点的估价距离
    heap.push({dist[start] + f(start), start});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        string state = t.y;
        // int d = t.x;
        
        if (state == end) break;

        int x, y;
        for (int i = 0; i < 9; i++) 
            if (state[i] == 'x') {
                x = i / 3, y = i % 3;
                break;
            }
        
        string source = state;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];

            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            
            swap(state[a * 3 + b], state[x * 3 + y]);
            
            // cout << d << " " << dist[source] <<endl;
            // 有必要扩展再去扩展
            // 我们在扩展每个点时不能使用堆中的存的那个距离去扩展下一个状态
            // 因为那个距离不是我们需要的距离（这个状态到起始状态的实际距离，而堆中的那个距离是实际距离+估价距离），我们要使用dist数组中的值去扩展下一个状态
            if (dist.count(state) == 0 || dist[state] > dist[source] + 1) {
                dist[state] = dist[source] + 1;
                prev[state] = {op[i], source};
                heap.push({dist[state] + f(state), state});
            }
            state = source;
        }
    }

    string res;
    while (end != start) {
        res += prev[end].x;
        end = prev[end].y;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    string start, judge;
    char c;

    while (cin >> c) {
        if (c != 'x') judge += c;
        start += c;
    }

    int cnt = 0;
    for (int i = 0; i < 8; i++)
        for (int j = i; j < 8; j++)
            if (judge[i] > judge[j])
                cnt ++;

    if (cnt & 1) puts("unsolvable");
    else cout << bfs(start) << endl;

    return 0;
}