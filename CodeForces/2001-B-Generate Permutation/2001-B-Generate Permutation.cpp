#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
    } else {
        vector<int> perm(n);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                perm[l++] = i + 1;
            } else {
                perm[r--] = i + 1;
            }
        }
        for (int x : perm) {
            cout << x << " ";
        }
        cout << endl;
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
