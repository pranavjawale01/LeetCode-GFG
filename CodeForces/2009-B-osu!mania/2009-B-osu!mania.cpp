#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int r;
    cin >> r;
    vector<int> ans(r, 0);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < 4; j++) {
            char x;
            cin >> x;
            if (x == '#') {
                ans[i] = j + 1;
            }
        }
    }
    for (int i = r - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
