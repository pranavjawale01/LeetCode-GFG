#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int i = -1;
    while (i < n) {
        while (i >= 0 && i < n && s[i] == 'W') {
            i++;
            k--;
            if (k < 0) {
                cout << "NO" << endl;
                return;
            }
        }
        if (i < n && s[i] == 'C') {
            cout << "NO" << endl;
            return;
        }
        bool flag = false;
        for (int j = m; j >= 1; j--) {
            if (i + j >= n) {
                cout << "YES" << endl;
                return;
            }
            if (i + j < n && s[i + j] == 'L') {
                i += j;
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }
        for (int j = m; j >= 1; j--) {
            if (i + j < n && s[i + j] == 'W') {
                i += j;
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
