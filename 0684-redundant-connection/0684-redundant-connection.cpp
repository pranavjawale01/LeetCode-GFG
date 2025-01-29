class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &mp, int u, int v, vector<bool> &vis) {
        vis[u] = true;
        if (u == v) return true;
        for (auto &x : mp[u]) {
            if (vis[x]) continue;
            if (dfs(mp, x, v, vis)) return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> mp;
        for (auto &x : edges) {
            int u = x[0], v = x[1];
            vector<bool> vis(n + 1, false);
            if (mp.count(u) && mp.count(v) && dfs(mp, u, v, vis)) {
                return x;
            }
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return {};
    }
};