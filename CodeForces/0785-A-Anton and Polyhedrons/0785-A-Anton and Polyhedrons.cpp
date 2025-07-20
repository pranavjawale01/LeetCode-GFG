#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'T') {
            count += 4;
        }
        if (s[0] == 'C') {
            count += 6;
        }
        if (s[0] == 'O') {
            count += 8;
        }
        if (s[0] == 'D') {
            count += 12;
        }
        if (s[0] == 'I') {
            count += 20;
        }
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
