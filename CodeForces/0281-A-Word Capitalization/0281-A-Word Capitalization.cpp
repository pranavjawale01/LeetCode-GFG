#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    string s;
    cin >> s;
    if (isupper(s[0])) {
        cout << s << endl;
    } else {
        s[0] = s[0] - 32;
        cout << s << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
