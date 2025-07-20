#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int a, b;
    cin >> a >> b;
    int year = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        year++;
    }
    cout << year << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pranavjawale01();
    return 0;
}
