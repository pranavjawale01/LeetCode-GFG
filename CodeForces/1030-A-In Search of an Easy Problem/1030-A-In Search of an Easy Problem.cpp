#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += x;
    }
    if (ans) {
        cout << "HARD" << endl;
    } else {
        cout << "EASY" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
