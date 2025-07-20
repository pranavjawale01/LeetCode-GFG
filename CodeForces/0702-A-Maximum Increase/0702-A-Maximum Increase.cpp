#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 1;
    int curr = 1;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) {
            curr++;
        } else {
            ans = max(ans, curr);
            curr = 1;
        }
    }
    
    ans = max(ans, curr);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    pranavjawale01();
    return 0;
}
