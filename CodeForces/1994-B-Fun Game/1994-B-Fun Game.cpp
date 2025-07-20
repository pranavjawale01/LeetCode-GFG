#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;

    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flag = true;
        }
        if (s[i] == '0' && t[i] == '1' && !flag) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
