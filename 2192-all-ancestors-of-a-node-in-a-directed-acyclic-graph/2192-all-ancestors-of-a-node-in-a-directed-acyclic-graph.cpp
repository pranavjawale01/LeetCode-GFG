class Solution {
public:
    vector<vector<int>> ans;
    void solve(unordered_map<int, vector<int>> &mp, int node, vector<int> &temp, vector<bool> &vis) {
        if (vis[node]) {
            return;
        }
        vis[node] = true;
        for (auto x : mp[node]) {
            if (!vis[x]) {
                temp.push_back(x);
                solve(mp, x, temp, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        ans.resize(n);
        for (auto edge : edges) {
            mp[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            vector<bool> visited(n, false);
            solve(mp, i, temp, visited);
            sort(temp.begin(), temp.end());
            ans[i] = temp;
        }
        return ans;
    }
};