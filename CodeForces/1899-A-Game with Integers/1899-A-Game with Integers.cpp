#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    if (n % 3 == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
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
