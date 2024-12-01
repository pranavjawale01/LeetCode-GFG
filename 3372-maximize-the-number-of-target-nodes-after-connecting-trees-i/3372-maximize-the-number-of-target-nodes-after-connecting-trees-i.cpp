class Solution {
public:
    int bfs(unordered_map<int, vector<int>> &mp, int start, int k, int size) {
        vector<bool> vis(size);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        int cnt = 0, dist = 0;
        while (!q.empty() && dist <= k) {
            int len = q.size();
            while (len--) {
                int node = q.front();
                q.pop();
                cnt++;
                for (int x : mp[node]) {
                    if (!vis[x]) {
                        vis[x] = true;
                        q.push(x);
                    }
                }
            }
            dist++;
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size(), m = edges2.size();
        unordered_map<int, vector<int>> mp1, mp2;
        for (auto x : edges1) {
            mp1[x[0]].push_back(x[1]);
            mp1[x[1]].push_back(x[0]);
        }
        for (auto x : edges2) {
            mp2[x[0]].push_back(x[1]);
            mp2[x[1]].push_back(x[0]);
        }
        vector<int> count(n+1);
        for (int i = 0; i <= n; i++) {
            count[i] = bfs(mp1, i, k, n+1);
        }
        int maxCountNode = 0;
        for (int i = 0; i <= m; i++) {
            maxCountNode = max(maxCountNode, bfs(mp2, i, k - 1, m + 1));
        }
        vector<int> ans(n+1);
        for (int i = 0; i <= n; i++) {
            ans[i] = count[i] + maxCountNode;
        }
        return ans;
    }
};