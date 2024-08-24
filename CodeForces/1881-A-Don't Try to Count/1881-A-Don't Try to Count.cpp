#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    int count = 6, result = 0;
    bool flag = false;
    while (count--) {
        if (x.find(s) != string::npos) {
            flag = true;
            break;
        }
        result++;
        x += x;
    }
    if (flag) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
