#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == k) {
            flag = true;
        }
    }
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
