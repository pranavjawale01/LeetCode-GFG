#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c) {
    int count = 5;
    while (count > 0) {
        if (a <= b && a <= c) {
            a++;
        } else if (b <= a && b <= c) {
            b++;
        } else {
            c++;
        }
        count--;
    }
    return a * b * c;
}

int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << endl;
    }
    
    return 0;
}
