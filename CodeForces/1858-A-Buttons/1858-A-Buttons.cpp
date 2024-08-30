#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int a, b, c;
    cin >> a >> b >> c;
    
    bool isOdd = (c & 1);
    
    if (isOdd) {
        if (a >= b) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    } else {
        if (a > b) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
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
