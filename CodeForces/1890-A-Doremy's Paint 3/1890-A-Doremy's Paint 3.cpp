#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    if (mp.size() == 1) {
        cout << "YES" << endl;
    } else if (mp.size() == 2) {
        auto it = mp.begin();
        int freq1 = it->second;
        it++;
        int freq2 = it->second;
        if (abs(freq1 - freq2) <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
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
