#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;

    vector<long long> arr(n, 0);
    bool flag = false;

    if (n == 2) {
        cout << "1 1" << endl;
        return;
    }

    for (long long i = x + 1; i < n; i++) {
        if (flag) {
            arr[i] = 1;
        } else {
            arr[i] = -1;
        }
        flag = !flag;
    }

    for (long long i = y; i <= x; i++) {
        arr[i] = 1;
    }

    flag = false;
    for (long long i = y - 1; i >= 0; i--) {
        if (flag) {
            arr[i] = 1;
        } else {
            arr[i] = -1;
        }
        flag = !flag;
    }

    for (long long i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
