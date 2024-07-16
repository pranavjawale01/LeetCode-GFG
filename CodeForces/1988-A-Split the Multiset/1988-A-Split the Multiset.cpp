#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int count = 0;
    if (n <= k) {
        if (n == 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return;
    }
    while (n > 1) {
        count++;
        n -= (k-1);
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
