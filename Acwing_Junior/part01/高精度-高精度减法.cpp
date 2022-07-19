#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) return a.size() > b.size();

    for (int i = a.size() - 1; i >= 0; i --) 
        if (a[i] != b[i]) return a[i] > b[i];
    
    return true;
}

vector<int> sub(vector<int>& a, vector<int>& b) {
    int t = 0;
    vector<int> res;
    for (int i = 0; i < a.size(); i ++) {
        t = a[i] - t;
        if (i < b.size()) t -= b[i];
        res.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (res.back() == 0 && res.size() > 1) res.pop_back();

    return res;
}

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> num1, num2;
    for (int i = a.size() - 1; i >= 0; i --) num1.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) num2.push_back(b[i] - '0');

    bool flag = cmp(num1, num2);
    vector<int> res = flag ? sub(num1, num2) : sub(num2, num1);

    if (!flag) cout << "-";
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
    cout << endl;

    return 0;
}