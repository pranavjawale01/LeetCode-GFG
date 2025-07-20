#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int totalDrink = k * l;

    int totalSlice = c * d;

    int drinkToast = totalDrink / nl;
    int limeToast = totalSlice;
    int saltToast = p / np;

    int toastPerFriend = min({drinkToast, limeToast, saltToast}) / n;

    cout << toastPerFriend << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
