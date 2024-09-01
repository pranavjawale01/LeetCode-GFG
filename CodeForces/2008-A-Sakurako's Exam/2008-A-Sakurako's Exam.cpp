#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int a, b;
    cin >> a >> b;
    int totalSum = 2 * b + a;
    if (totalSum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        if (b % 2 != 0 && a == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;  // Removed initialization t = 1
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
