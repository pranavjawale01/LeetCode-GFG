class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(i);
        }
        vector<int> ans;
        for (auto x : queries) {
            auto a = st.lower_bound(x[0] + 1);
            auto b = st.upper_bound(x[1] - 1);
            st.erase(a, b);
            ans.push_back(st.size() - 1);
        }
        return ans;
    }
};