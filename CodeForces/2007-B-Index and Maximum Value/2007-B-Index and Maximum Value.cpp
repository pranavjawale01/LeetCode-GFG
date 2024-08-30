#include<bits/stdc++.h>
using namespace std;

#define ll long long

void pranavjawale01() {
    ll n, m;
    cin >> n >> m;
    ll maxEl = 0;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        maxEl = max(maxEl, arr[i]);
    }
    while (m--) {
        char sign;
        ll a, b;
        cin >> sign >> a >> b;
        if (a <= maxEl && maxEl <= b) {
            if (sign == '-') {
                maxEl--;
            } else {
                maxEl++;
            }
        }
        cout << maxEl << " ";
    }
    cout << endl;
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
