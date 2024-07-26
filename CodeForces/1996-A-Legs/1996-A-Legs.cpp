#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cow = n / 4;
    n = n - cow * 4;
    int chicken = n / 2;
    cout << cow + chicken << endl;;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
