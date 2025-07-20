#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num % 2 == 1) {
            odd.push_back(num);
        } else {
            even.push_back(num);
        }
    }

    if (odd.empty() || even.empty()) {
        cout << 0 << endl;
        return;
    } 

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    
    ll max_odd = odd.back();
    ll ans = even.size();

    for (int x : even) {
        if (x > max_odd) {
            ans++;
            break;
        }
        max_odd += x;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
