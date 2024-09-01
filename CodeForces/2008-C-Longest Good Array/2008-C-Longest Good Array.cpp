#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    long long l, r;  
    cin >> l >> r;  
    
    int maxLen = 0;  
    long long currSum = 0;  
    
    while (true) {  
        if (currSum + (maxLen + 1) <= r - l) {  
            currSum += (maxLen + 1);  
            maxLen++;  
        } else {  
            break;  
        }  
    }  
    cout << maxLen + 1 << endl;  
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
