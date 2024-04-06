class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.length();
        unordered_set<int> remove_idx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    remove_idx.insert(i);
                } else {
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
            remove_idx.insert(st.top());
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (remove_idx.find(i) == remove_idx.end()) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};