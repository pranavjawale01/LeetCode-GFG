#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000001;

void solve() {
    int n, x;
    cin >> n >> x;
    ll count = 0;

    for (int a = 1; a <= x - 2; ++a) {
        for (int b = 1; b <= x - a - 1; ++b) {
            if (a * b >= n) break;

            int maxC1 = x - a - b;
            int maxC2 = (n - a * b) / (a + b);
            int maxC = min(maxC1, maxC2);

            if (maxC > 0) {
                count += maxC;
            }
        }
    }

    cout << count << '\n';
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
