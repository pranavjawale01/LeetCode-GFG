#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<char>> matrix(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int len = n / k;
    vector<vector<char>> ans(len, vector<char>(len));
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            ans[i][j] = matrix[i * k][j * k];
        }
    }
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cout << ans[i][j];
        }
        cout << endl;
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
