#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void pranavjawale01() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    int g = gcd(a, b);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= g;
    }
    
    sort(arr.begin(), arr.end());
    
    ll ans = arr[n-1] - arr[0];
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, (ll)(g - arr[i+1] + arr[i]));
    }
    
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
