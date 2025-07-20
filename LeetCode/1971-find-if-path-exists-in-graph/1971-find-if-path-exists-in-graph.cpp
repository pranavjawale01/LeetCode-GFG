class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        for (vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination) {
                return true;
            }
            for (auto &V : mp[node]) {
                if (!visited[V]) {
                    q.push(V);
                    visited[V] = true;
                }
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool check(unordered_map<int, vector<int>> &mp, int s, int d, vector<bool> &visited) {
//         if (s == d) {
//             return true;
//         }
//         if (visited[s]) {
//             return false;
//         }
//         visited[s] = true;
//         for (auto &node : mp[s]) {
//             if (check(mp, node, d, visited)) {
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         unordered_map<int, vector<int>> mp;
//         for (vector<int> &edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             mp[u].push_back(v);
//             mp[v].push_back(u);
//         }
//         vector<bool> visited(n, false);
//         return check(mp, source, destination, visited);
//     }
// };