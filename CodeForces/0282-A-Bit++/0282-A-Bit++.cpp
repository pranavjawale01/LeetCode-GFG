#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int x = 0, n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s[1] == '+') {
            x++;
        } else if (s[1] == '-') {
            x--;
        }
    }

    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pranavjawale01();
    return 0;
}
