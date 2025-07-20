class Solution {
public:
    void BFS(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        queue<int> q;
        q.push(i);
        int n = isConnected.size();
        visited[i] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int v = 0; v < n; v++) {
                if (!visited[v] && isConnected[i][v] == 1) {
                    BFS(isConnected, v, visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                BFS(isConnected, i, visited);
                count++;
            }
        }
        return count; 
    }
};

// class Solution {
// public:
//     void DFS(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
//         visited[i] = true;
//         int n = isConnected.size();
//         for (int v = 0; v < n; v++) {
//             if (!visited[v] && isConnected[i][v]) {
//                 DFS(isConnected, v, visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int count = 0;
//         int n = isConnected.size();
//         vector<bool> visited(n, false);
        
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 DFS(isConnected, i, visited);
//                 count++;
//             }
//         }
//         return count; 
//     }
// };

// class Solution {
// public:
//     void DFS(unordered_map<int, vector<int>> &adj, int i, vector<bool>& visited) {
//         visited[i] = true;
//         for (int &v : adj[i]) {
//             if (!visited[v]) {
//                 DFS(adj, v, visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int count = 0;
//         int n = isConnected.size();
//         vector<bool> visited(n, false);
//         unordered_map<int, vector<int>> adj;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (isConnected[i][j] == 1) {
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 DFS(adj, i, visited);
//                 count++;
//             }
//         }
//         return count; 
//     }
// }