#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    string tableCard = "";
    cin >> tableCard;
    bool ans = false;
    
    for (int i = 0; i < 5; i++) {
        string x;
        cin >> x;
        
        if (x[1] == tableCard[1] || x[0] == tableCard[0]) {
            ans = true;
        }
    }
    
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
