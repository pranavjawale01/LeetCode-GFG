#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool isSorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }
    
    if (!isSorted) {
        cout << 0 << endl;
        return;
    }

    int minOps = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        minOps = min(minOps, abs(arr[i] - arr[i + 1]));
    }
    
    cout << (minOps / 2) + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
