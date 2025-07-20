#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    for (auto x : mp) {
        if (x.second % 2 != 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve(0);
    }  
    return 0;
}
