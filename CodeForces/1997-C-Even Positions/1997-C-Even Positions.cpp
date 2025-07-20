#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') {
            if (st.empty()) {
                st.push(i);
            } else {
                ans += i - st.top();
                st.pop();
            }
        }
        if (s[i] == '(') {
            st.push(i);
        }
        if (s[i] == ')') {
            ans += i - st.top();
            st.pop();
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
