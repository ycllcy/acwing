#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> add(vector<int>& a, vector<int>& b) {
    int t = 0;
    vector<int> res;
    for (int i = 0; i < a.size() || i < b.size(); i ++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }

    if (t > 0) res.push_back(t);

    return res;
}

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> num1, num2;
    for (int i = a.size() - 1; i >= 0; i --) num1.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) num2.push_back(b[i] - '0');

    vector<int> res = add(num1, num2);

    for (int i = res.size() - 1; i >= 0; i --) cout << res[i];
    cout << endl;

    return 0;
}