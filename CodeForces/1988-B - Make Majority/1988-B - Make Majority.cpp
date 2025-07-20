#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    string s;
    cin >> s;
    
    if (s[0] == '1' && s[n-1] == '1') {
        cout << "Yes" << endl;
        return;
    }
    bool front = false, back = false;
    
    long long curr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            curr++;
        } else {
            curr = 0;
        }
        if (curr >= 2) {
            if (!front) {
                front = true;
            } else {
                back = true;
            }
        }
    }
    if (s[0] == '1' || s[n-1] == '1') {
        if (front) {
            cout << "Yes" << endl;
            return;
        }
    }
    if (back) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
