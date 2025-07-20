#include <bits/stdc++.h>
using namespace std;

#define ll long long

void pranavjawale01() {
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    while (k--) {
        if (n % 10 != 0) {
            n--;
        } else {
            n /= 10;
        }
    }
    cout << n << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
