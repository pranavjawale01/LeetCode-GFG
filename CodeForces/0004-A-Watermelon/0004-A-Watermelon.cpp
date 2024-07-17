#include<bits/stdc++.h>
using namespace std;

int main() {
    int w;
    cin >> w;
    string ans = w % 2 == 0 && w > 2 ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}
