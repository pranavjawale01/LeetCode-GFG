#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int a, b, n;
    cin >> a >> b >> n;

    if (a > b) {
        swap(a, b);
    }

    int count = 0;
    
    while (a <= n && b <= n) {
        a += b;
        swap(a, b);
        count++;
    }
    
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        pranavjawale01();
    }
    
    return 0;
}
