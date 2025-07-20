#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

void inputArr(ll n, ll arr[]) {
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll arr[n];
    inputArr(n, arr);

    ll brr[2 * k + 1] = {0};
    for (auto i : arr) {
        brr[i % (2 * k)]++;
    }
    brr[2 * k] = brr[0];

    for (ll i = 1; i <= k; i++) {
        if (brr[i] > 0 && brr[i + k] > 0) {
            cout << "-1" << nl;
            return;
        }
    }

    ll first = 0;
    ll last = 0;

    for (ll i = 1; i <= 2 * k; i++) {
        if (brr[i] > 0) {
            if (first == 0) first = i;
            last = i;
        }
    }

    ll ans = 0;
    if (last - first < k) {
        ans = last;
    } else {
        for (ll i = k + 1; i <= 2 * k; i++) {
            if (brr[i] > 0) {
                ans = i;
                break;
            }
        }
        ll maxreach = (ans + k) % (2 * k);
        for (ll i = maxreach + 1; i <= k; i++) {
            if (brr[i] > 0) {
                cout << "-1" << nl;
                return;
            }
        }
        for (ll i = 1; i <= k; i++) {
            if (brr[i] > 0) ans = i;
        }
    }

    sort(arr, arr + n);
    ll maxm = arr[n - 1];

    if (ans == 2 * k) ans = 0;

    for (ll i = maxm; i < maxm + 2 * k + 1; i++) {
        if (i % (2 * k) == ans) {
            cout << i << nl;
            return;
        }
    }
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
