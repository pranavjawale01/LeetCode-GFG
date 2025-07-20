#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    ll s, m;
    cin >> n >> s >> m;
    
    vector<pair<ll, ll>> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    sort(arr.begin(), arr.end());
    
    if (arr[0].first >= s) {
        cout << "YES" << endl;
        return;
    }
    
    for (int i = 1; i < n; ++i) {
        if (arr[i].first - arr[i - 1].second >= s) {
            cout << "YES" << endl;
            return;
        }
    }
    
    if (m - arr[n - 1].second >= s) {
        cout << "YES" << endl;
        return;
    }
    
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
