#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void pranavjawale01() {
    ll n;
    cin >> n;
    set<ll> x, y;

    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (b == 0) {
            x.insert(a);
        } else {
            y.insert(a);
        }
    }

    ll ans = 0;

    for (ll a : x) {
        if (y.find(a) != y.end()) {
            ans += x.size() + y.size() - 2;
        }
    }

    for (ll a : x) {
        if (y.find(a + 1) != y.end() && x.find(a + 2) != x.end()) {
            ans++;
        }
    }

    for (ll b : y) {
        if (x.find(b - 1) != x.end() && y.find(b - 2) != y.end()) {
            ans++;
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
