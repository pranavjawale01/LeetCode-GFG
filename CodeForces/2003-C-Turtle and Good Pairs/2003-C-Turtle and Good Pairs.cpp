#include <bits/stdc++.h>
using namespace std;

void pranavjawale01() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto x : mp) {
        pq.push({x.second, x.first});
    }

    string ans = "";
    while (pq.size() > 1) {
        auto it1 = pq.top();
        pq.pop();
        auto it2 = pq.top();
        pq.pop();

        ans += it1.second;
        ans += it2.second;

        if (it1.first > 1) {
            pq.push({it1.first - 1, it1.second});
        }
        if (it2.first > 1) {
            pq.push({it2.first - 1, it2.second});
        }
    }

    if (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        for (int i = 0; i < it.first; i++) {
            ans += it.second;
        }
    }

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
