#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vector<vector<int>> prefixA(n + 1, vector<int>(26, 0));
    vector<vector<int>> prefixB(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            prefixA[i][j] = prefixA[i - 1][j] + (a[i - 1] - 'a' == j);
            prefixB[i][j] = prefixB[i - 1][j] + (b[i - 1] - 'a' == j);
        }
    }

    vector<vector<int>> query(q, vector<int>(2, 0));
    for (int i = 0; i < q; ++i) {
        cin >> query[i][0] >> query[i][1];
    }

    for (auto &x : query) {
        int l = x[0];
        int r = x[1];

        vector<int> freqA(26, 0), freqB(26, 0);
        for (int j = 0; j < 26; ++j) {
            freqA[j] = prefixA[r][j] - prefixA[l - 1][j];
            freqB[j] = prefixB[r][j] - prefixB[l - 1][j];
        }

        int operations = 0;
        for (int j = 0; j < 26; ++j) {
            operations += abs(freqA[j] - freqB[j]);
        }

        cout << operations / 2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
