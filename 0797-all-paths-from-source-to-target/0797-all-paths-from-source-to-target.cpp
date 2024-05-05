class Solution {
public:
    vector<vector<int>> ans;
    void solve(unordered_map<int, vector<int>> &mp, vector<int> &temp, int n, int source) {
        if (source == n - 1) {
            temp.push_back(source);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(source);
        for (auto x : mp[source]) {
            solve(mp, temp, n, x);
        }
        temp.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> mp;
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            for (int x : graph[i]) {
                mp[i].push_back(x);
            }
        }
        vector<int> temp;
        solve(mp, temp, n, 0);
        return ans;
    }
};