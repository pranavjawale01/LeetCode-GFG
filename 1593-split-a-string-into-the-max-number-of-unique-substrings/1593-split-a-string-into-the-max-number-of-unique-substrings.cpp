class Solution {
public:
    unordered_set<string> st;
    void solve(string &s, int i, string t) {
        if (i >= s.size()) return;
        t += s[i];
        if (st.find(t) != st.end()) {
            solve(s, i+1, t);
        } else {
            st.insert(t);
            solve(s, i+1, "");
        }
    }
    int maxUniqueSplit(string s) {
        solve(s, 0, "");
        return st.size();
    }
};