#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c && b > d && a > d && b > c) {
        cout << "4" << endl;
    } else if (((a > c && b >= d) || (a >= c && b > d)) && ((a > d && b >= c) || (a >= d && b > c))) {
        cout << "4" << endl;
    } else if ((a > c && b >= d) || (a >= c && b > d) || (a > d && b >= c) || (a >= d && b > c)) {
        cout << "2" << endl;
    } else {
        cout << "0" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
