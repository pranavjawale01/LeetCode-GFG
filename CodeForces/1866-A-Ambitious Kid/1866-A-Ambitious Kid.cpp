#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int ans = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans = min(ans, abs(arr[i]));
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
