#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    string s;
    cin >> n >> s;
    int r = sqrt(n);
    if (r * r != n) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < r; i++) {
        if (s[i] != '1' || s[n - r + i] != '1') {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 1; i < r - 1; i++) {
        if (s[i * r] != '1' || s[i * r + r - 1] != '1') {
            cout << "NO" << endl;
            return;
        }
        for (int j = 1; j < r - 1; j++) {
            if (s[i * r + j] != '0') {
                cout << "NO" << endl;
                return;
            }
        }
    }
    
    cout << "YES" << endl;
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
