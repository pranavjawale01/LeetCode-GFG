#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll largeOdd = 0, largeEven = 0;

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 1) {
            largeOdd = max(largeOdd, arr[i]);
        } else {
            largeEven = max(largeEven, arr[i]);
        }
    }

    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] % 2 != arr[0] % 2) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << 0 << endl;
        return;
    }

    sort(arr.begin(), arr.end());
    int c = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] < largeOdd) {
            c++;
            arr[i] += largeOdd;
            largeOdd = max(largeOdd, arr[i]);
        }
    }

    flag = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] % 2 != arr[0] % 2) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << c << endl;
        return;
    }

    ll idx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1 && arr[i] == largeOdd) {
            idx = i;
            break;
        }
    }

    arr[idx] = largeOdd + largeEven;
    c++;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            c++;
        }
    }

    cout << c << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
