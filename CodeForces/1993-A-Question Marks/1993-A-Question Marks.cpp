#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countQ = 0;
    
    for (char c : s) {
        if (c == 'A') {
            countA++;
        }
        if (c == 'B') {
            countB++;
        }
        if (c == 'C') {
            countC++;
        }
        if (c == 'D') {
            countD++;
        }
        if (c == '?') {
            countQ++;
        }
    }
    
    int maxA = min(countA, n);
    int maxB = min(countB, n);
    int maxC = min(countC, n);
    int maxD = min(countD, n);
    
    cout << maxA + maxB + maxC + maxD << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
