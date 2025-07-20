#include <bits/stdc++.h>
using namespace std;

#define ll long long 

void pranavjawale01() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (i & 1) {
            ans -= x;
        } else {
            ans += x;
        }
    }
    cout << ans << endl;
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
