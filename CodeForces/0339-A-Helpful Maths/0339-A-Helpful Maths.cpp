#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    string s;
    cin >> s;
    int one = 0, two = 0, three = 0;
    
    for (char c : s) {
        if (c == '1') one++;
        if (c == '2') two++;
        if (c == '3') three++;
    }
    
    string ans = "";
    
    while (one--) {
        ans += '1';
        ans += '+';
    }
    
    while (two--) {
        ans += '2';
        ans += '+';
    }
    
    while (three--) {
        ans += '3';
        ans += '+';
    }
    
    if (!ans.empty()) {
        ans.pop_back();
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
