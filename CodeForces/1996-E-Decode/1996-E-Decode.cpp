#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long add(long long a, long long b) {
    return (a + b) % mod;
}

long long mult(long long a, long long b) {
    return (a * b) % mod;
}

void solve() {
    string s;
    cin >> s;
    long long n = s.size();
    map<long long, long long> mp;
    mp[0] = 1;
    long long curr = 0;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        curr += (s[i] == '1' ? 1 : -1);
        ans = add(ans, mult(mp[curr], n - i));
        mp[curr] += (i + 2);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
