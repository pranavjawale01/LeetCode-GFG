#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    int m = a.length(), n = b.length();
    
    while (i < m && j < n) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else if (a[i] == '?') {
            a[i] = b[j];
            i++;
            j++;
        } else {
            i++;
        }
    }
    
    if (i >= m && j < n) {
        cout << "NO" << endl;
    } else {
        for (int k = 0; k < m; k++) {
            if (a[k] == '?') {
                a[k] = 'a';
            }
        }
        cout << "YES" << endl;
        cout << a << endl;
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
