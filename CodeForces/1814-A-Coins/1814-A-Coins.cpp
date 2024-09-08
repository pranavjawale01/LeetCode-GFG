#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    long long n, k;
    cin >> n >> k;
    if ((n - k) % 2 == 0 || n % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        pranavjawale01();
    }
    
    return 0;
}
