#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> arr(2);
    cin >> arr[0];
    cin >> arr[1];

    int count = 0;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (j+2 < n && i + 1 < 2 && arr[i][j] == 'x' && arr[i][j+2] == 'x' && arr[i][j+1] == '.' && arr[i+1][j+1] == '.' && arr[i+1][j] == '.' && arr[i+1][j+2] == '.') {
                count++;
            }
            if (i-1 >= 0 && j+2 < n && arr[i][j] == 'x' && arr[i][j+2] == 'x' && arr[i][j+1] == '.' && arr[i-1][j] == '.' && arr[i-1][j+1] == '.' && arr[i-1][j+2] == '.') {
                count++;
            }
        }
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
