class Solution {
public:
    int dijikstras(int s, int n, vector<vector<int>> &mp) {
        vector<int> dist(n, n);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : mp[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> mp(n);
        for (int i = 0; i < n - 1; i++) {
            mp[i].push_back(i+1);
        }
        for (auto x : queries) {
            mp[x[0]].push_back(x[1]);
            ans.push_back(dijikstras(0, n, mp));
        }
        return ans;
    }
};