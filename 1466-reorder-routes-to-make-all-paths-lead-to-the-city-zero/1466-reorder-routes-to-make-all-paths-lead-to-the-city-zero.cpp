class Solution {
public:
    int count = 0;
    
    void dfs(unordered_map<int, vector<pair<int, int>>> &adj, int source, int parent) {
        for (auto &p : adj[source]) {
            int v = p.first;
            int c = p.second;
            if (v != parent) {
                if (c == 1) {
                    count++;
                }
                dfs(adj, v, source);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for (vector<int>& con : connections) {
            adj[con[0]].push_back({con[1], 1});
            adj[con[1]].push_back({con[0], 0});
        }
        
        dfs(adj, 0, -1);
        return count;
    }
};