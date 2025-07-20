class Solution {
public:
    int ans = 0;
    unordered_set<string> st;
    void solve(string &s, int i, string t) {
        if (i == s.size()) {
            ans = max(ans, (int)st.size());
            return;
        }
        for (int j = i; j < s.size(); j++) {
            t += s[j];
            if (st.find(t) == st.end()) {
                st.insert(t);
                solve(s, j+1, "");
                st.erase(t);
            }
        }
    }
    int maxUniqueSplit(string s) {
        solve(s, 0, "");
        return ans;
    }
};