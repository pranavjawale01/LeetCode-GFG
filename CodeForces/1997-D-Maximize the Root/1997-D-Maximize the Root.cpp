#include <bits/stdc++.h>
using namespace std;

long long solve(long long node, vector<long long> &arr, vector<vector<long long>> &child) {
    long long ans = arr[node - 1];
    long long minm = INT_MAX;
    if (child[node].empty()) {
        return ans;
    }
    for (auto i : child[node]) {
        minm = min(minm, solve(i, arr, child));
    }
    if (node == 1) {
        ans += minm;
        return ans;
    }
    if (minm < ans) {
        return minm;
    }
    ans = (ans + minm) / 2;
    return ans;
}

void helper() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<long long>> child(n + 1);
    for (long long i = 2; i <= n; i++) {
        long long x;
        cin >> x;
        child[x].push_back(i);
    }
    long long ans = solve(1, arr, child);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        helper();
    }
    return 0;
}
