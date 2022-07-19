#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> mul(vector<int> a, int b) {
    int t = 0;
    vector<int> res;

    for (int i = 0; i < a.size(); i ++) {
        t += a[i] * b;
        res.push_back(t  % 10);
        t /= 10;
    }

    while (t > 0) {
        res.push_back(t % 10);
        t /= 10;
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();

    return res;
}

int main() {
    string a;
    int b;
    cin >> a >> b;

    vector<int> num;
    for (int i = a.size() - 1; i >= 0; i --) num.push_back(a[i] - '0');

    vector<int> res = mul(num, b);

    for (int i = res.size() - 1; i >= 0; i --) cout << res[i];
    cout << endl;

    return 0;
}