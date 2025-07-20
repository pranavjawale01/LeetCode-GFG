#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second
#define endl "\n"

const int MOD = 1e9 + 7;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void pranavjawale01() {
    int n, k;
    cin >> n >> k;
    vector<pii> d(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        d[i] = {t, i+1};
    }
    
    sort(all(d));

    int count = 0, sum = 0;
    for (auto p : d) {
        if (sum + p.ff > k) break;
        sum += p.ff;
        count++;
    }

    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << d[i].ss << " ";
    }
    cout << endl;
}

int main() {
    fast_io();
    int t = 1;
    while (t--) {
        pranavjawale01();
    }
    return 0;
}
