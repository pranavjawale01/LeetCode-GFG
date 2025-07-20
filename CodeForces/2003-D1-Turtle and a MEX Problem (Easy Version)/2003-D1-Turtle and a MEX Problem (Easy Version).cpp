#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

ll mex(vector<ll> &arr) {
    ll n = arr.size();
    set<ll> hs;
    for (ll i = 0; i <= n + 1; i++) 
        hs.insert(i);

    for (auto i : arr) 
        hs.erase(i);

    hs.erase(*(hs.begin()));
    return *(hs.begin());
}

void inputArr(ll s, vector<ll> &v) {
    for (ll i = 0; i < s; i++) {
        ll val;
        cin >> val;
        v.push_back(val);
    }
}

void pranavjawale01() {
    ll n, m;
    cin >> n >> m;

    vector<ll> arr[n];
    for (ll i = 0; i < n; i++) {
        ll s;
        cin >> s;
        inputArr(s, arr[i]);
    }

    ll maxm = 0;
    for (ll i = 0; i < n; i++) {
        maxm = max(maxm, mex(arr[i]));
    }

    if (maxm >= m) {
        cout << (m + 1) * maxm << nl;
        return;
    }

    ll ans = (maxm + 1) * maxm + (m * (m + 1)) / 2 - (maxm * (maxm + 1)) / 2;
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
