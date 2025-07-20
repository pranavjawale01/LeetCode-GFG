#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    string x;
    cin >> x;

    if (x[0] != '9') {
        x[0] = min(x[0], char('9' - x[0] + '0'));
    }

    for (int i = 1; i < x.length(); i++) {
        x[i] = min(x[i], char('9' - x[i] + '0'));
    }

    cout << x << endl;
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
