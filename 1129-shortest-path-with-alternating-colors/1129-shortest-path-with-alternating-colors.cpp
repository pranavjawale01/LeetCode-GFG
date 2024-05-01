class Solution {
public:
    int bfs(vector<vector<pair<int, int>>> &adj, int dest) {
        int res = INT_MAX;
        queue<vector<int>> q;
        q.push({0, 0, 0});
        while (!q.empty()) {
            int curr = q.front()[0], color = q.front()[1], step = q.front()[2];
            q.pop();

            for (int i = 0; i < adj[curr].size(); i++) {
                if (adj[curr][i].first != -1 && adj[curr][i].second != color) {
                    q.push({adj[curr][i].first , adj[curr][i].second, step + 1});
                    if (adj[curr][i].first == dest) {
                        res = min(res, step + 1);
                    }
                    adj[curr][i] = {-1, -1};
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> ans;
        ans.push_back(0);

        for(auto x: redEdges)
            adj[x[0]].push_back({x[1], 1});
            
        for(auto x: blueEdges)
            adj[x[0]].push_back({x[1], 2});

        for(int i=1; i<n; i++)
            ans.push_back(bfs(adj, i));

        return ans;
    }
};