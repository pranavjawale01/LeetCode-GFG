#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int l, r;
    cin >> l >> r;
    if (!(l & 1)) {
        l++;
    }
    cout << (r - l + 2) / 4 << endl;
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
