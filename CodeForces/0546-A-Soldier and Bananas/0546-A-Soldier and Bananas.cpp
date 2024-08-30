#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int firstCost, dollar, wantToBuy;
    cin >> firstCost >> dollar >> wantToBuy;
    
    int totalCost = firstCost * ((wantToBuy * (wantToBuy + 1)) / 2);
    
    int borrow = totalCost - dollar;
    
    if (borrow > 0) {
        cout << borrow << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    //cin >> t;
    
    while (t--) {
        pranavjawale01();
    }
    
    return 0;
}
