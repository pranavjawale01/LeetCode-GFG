#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

void pranavjawale01() {
    ll n, k, x;
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES" << nl;
        cout << n << nl;
        for (ll i = 0; i < n; i++) cout << "1" << " ";
        cout << nl;
        return;
    }

    if (k == 1) {
        cout << "NO" << nl;
        return;
    }
    
    if (n % 2 == 0) {
        cout << "YES" << nl;
        cout << (n / 2) << nl;
        for (ll i = 0; i < n / 2; i++) cout << "2" << " ";
        cout << nl;
        return;
    }
    
    if (n % 2 != 0 && k < 3) {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;
    ll c = n / 2;
    cout << c << nl;
    for (ll i = 0; i < c - 1; i++) cout << "2" << " ";
    cout << "3" << nl;
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
