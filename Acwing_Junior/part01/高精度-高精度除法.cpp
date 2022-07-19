#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int div(vector<int> a, int b) {
    int t = 0;

    vector<int> res;
    for (int i = a.size() - 1; i >= 0; i --) {
        t = t * 10 + a[i];
        res.push_back(t / b);
        t %= b;
    }

    reverse(res.begin(), res.end());
    while (res.size() > 1 && res.back() == 0) res.pop_back();

    for (int i = res.size() - 1; i >= 0; i --) cout << res[i];
    cout << endl;

    return t;
}

int main() {
    string a;
    int b;
    cin >> a >> b;

    vector<int> num;
    for (int i = a.size() - 1; i >= 0; i --) num.push_back(a[i] - '0');

    int res = div(num, b);

    cout << res << endl;

    return 0;
}