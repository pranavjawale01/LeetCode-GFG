#include <bits/stdc++.h>
using namespace std;

#define ll long long

void pranavjawale01() {
    ll x, y, d;
    cin >> x >> y >> d;
    ll xStep, yStep;
    
    if (x % d == 0) {
        xStep = x / d;
    } else {
        xStep = (x / d) + 1;
    }

    if (y % d == 0) {
        yStep = y / d;
    } else {
        yStep = (y / d) + 1;
    }

    ll minDist = min(xStep, yStep);
    ll maxDist = max(xStep, yStep);
    ll ans = minDist + maxDist + (maxDist - minDist);
    
    if (xStep > yStep) {
        ans--;
    }

    cout << ans << endl;
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
