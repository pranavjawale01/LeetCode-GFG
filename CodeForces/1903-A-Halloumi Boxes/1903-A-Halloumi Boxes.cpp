#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if (k >= n) {
        cout << "YES" << endl;
        return;
    }
    
    vector<int> brr = arr;
    sort(brr.begin(), brr.end());
    if (brr == arr) {
        cout << "YES" << endl;
        return;
    }
    
    if (k >= 2) {
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
