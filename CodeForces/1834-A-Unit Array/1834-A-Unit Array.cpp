#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int pone = 0, none = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] == 1) {
            pone++;
        } else {
            none++;
        }
    }

    int ans = 0;
    
    while (!((pone - none) >= 0 && none % 2 == 0)) {
        ans++;
        pone++;
        none--;
    }

    cout << ans << endl;
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
