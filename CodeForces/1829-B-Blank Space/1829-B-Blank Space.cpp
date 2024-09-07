#include<bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            ans = max(curr, ans);
            curr = 0;
        } else {
            curr++;
        }
    }
    ans = max(ans, curr);
    cout << ans << endl;
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
