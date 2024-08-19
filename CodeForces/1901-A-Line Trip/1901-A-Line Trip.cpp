#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n, x;
    cin >> n >> x;
    vector<int> fuel(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> fuel[i];
    }
    
    int ans = abs(fuel[0] - 0);
    
    for (int i = 1; i < n; i++) {
        ans = max(ans, abs(fuel[i] - fuel[i-1]));
    }
    
    ans = max(ans, 2 * abs(fuel[n-1] - x));
    
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
