class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> indegree, outdegree;
        for (auto& x : pairs) {
            mp[x[0]].push_back(x[1]);
            indegree[x[1]];
            outdegree[x[0]];
        }
        for (auto& x : pairs) {
            outdegree[x[0]]++;
            indegree[x[1]]++;
        }
        int start = -1;
        for (auto& x : mp) {
            if (outdegree[x.first] - indegree[x.first] == 1) {
                start = x.first;
                break;
            }
        }
        if (start == -1) start = pairs[0][0];
        vector<int> path;
        stack<int> st;
        st.push(start);
        while (!st.empty()) {
            int curr = st.top();
            if (!mp[curr].empty()) {
                int ne = mp[curr].back();
                mp[curr].pop_back();
                st.push(ne);
            } else {
                path.push_back(curr);
                st.pop();
            }
        }
        reverse(path.begin(), path.end());
        vector<vector<int>> ans;
        int n = path.size();
        for (int i = 0; i < n - 1; i++) {
            ans.push_back({path[i], path[i + 1]});
        }
        return ans;
    }
};