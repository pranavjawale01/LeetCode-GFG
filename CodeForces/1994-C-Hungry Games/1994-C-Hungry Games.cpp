#include<bits/stdc++.h>
using namespace std;

long long findIndex(long long i, long long n, long long pref[], long long x) {
    if (i != 0) {
        x += pref[i-1];
    }
    if (i == n - 1) {
        return n+1;
    }
    long long low = i+1, high = n-1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (pref[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + 1;
}

void solve() {
    long long n, x;
    cin >> n >> x;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long pref[n] = {0};
    long long curr = 0;
    for (int i = 0; i < n; i++) {
        curr += arr[i];
        pref[i] = curr;
    }
    long long values[n] = {0};
    vector<long long> dp[n];
    for (long long i = 0; i < n; i++) {
        if (arr[i] > x) {
            if (i != n - 1) {
                dp[i+1].push_back(i);
            }
            continue;
        }
        long long idx = findIndex(i, n, pref, x);
        if (idx < n) {
            dp[idx].push_back(i);
        }
        values[i] = idx - i - 1;
    }
    for (long long i = n - 1; i >= 0; i--) {
        for (auto j : dp[i]) {
            values[j] += values[i];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += values[i];
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
