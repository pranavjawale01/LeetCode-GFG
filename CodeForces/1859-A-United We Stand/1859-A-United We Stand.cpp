#include <bits/stdc++.h>
using namespace std;

#define ll long long

void pranavjawale01() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a.back() == a[0]) {
        cout << -1 << endl;
        return;
    }
    ll idx = 0;
    while (a[idx] == a[0]) {
        idx++;
    }
    cout << idx << " " << n - idx << endl;
    for (int i = 0; i < idx; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = idx; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
