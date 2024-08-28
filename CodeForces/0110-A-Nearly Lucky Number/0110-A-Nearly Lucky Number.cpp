#include <bits/stdc++.h>
using namespace std;

#define ll long long

void pranavjawale01() {
    ll n;
    cin >> n;
    int count = 0;
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        if (digit == 4 || digit == 7) {
            count++;
        }
    }
    if (count == 4 || count == 7) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
