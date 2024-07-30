#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1) {
        if (s[0] == 'a') {
            s += 'b';
        } else {
            s += 'a';
        }
        cout << s << endl;
        return;
    }
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            flag = false;
            if (s[i] == 'a') {
                s.insert(i, 1, 'b');
            } else {
                s.insert(i, 1, 'a');
            }
            cout << s << endl;
            return;
        }
    }
    if (flag) {
        if (s[n-1] == 'a') {
            s += 'b';
        } else {
            s += 'a';
        }
        cout << s << endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
