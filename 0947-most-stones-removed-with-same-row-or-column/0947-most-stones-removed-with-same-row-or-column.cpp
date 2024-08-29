class Solution {
public:
    int n;
    void dfs(vector<vector<int>> &stones, int idx, vector<bool> &vis) {
        vis[idx] = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && ((stones[i][0] == stones[idx][0]) || stones[i][1] == stones[idx][1])) {
                dfs(stones, i, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool> vis(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            dfs(stones, i, vis);
            count++;
        }
        return n - count;
    }
};