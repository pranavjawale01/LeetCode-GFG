class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int i, vector<bool>& visited) {
        visited[i] = true;
        for (int &v : adj[i]) {
            if (!visited[v]) {
                DFS(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(adj, i, visited);
                count++;
            }
        }
        return count; 
    }
};