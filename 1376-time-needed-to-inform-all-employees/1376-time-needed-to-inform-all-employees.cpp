class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            if (manager[i] == -1) {
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        return bfs(headID, adj, informTime);
    }
    
    int bfs(int head, unordered_map<int, vector<int>>& adj, vector<int>& informTime) {
        queue<pair<int, int>> q;
        q.push({head, 0});
        int max_time = 0;
        while (!q.empty()) {
            auto [employee, time] = q.front();
            q.pop();
            max_time = max(max_time, time);
            for (int& sub : adj[employee]) {
                q.push({sub, time + informTime[employee]});
            }
        }
        return max_time;
    }
};



// class Solution {
// public:
//     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
//         unordered_map<int, vector<int>> adj;
//         for (int i = 0; i < n; i++) {
//             if (manager[i] == -1) {
//                 continue;
//             }
//             adj[manager[i]].push_back(i);
//         }
//         return dfs(headID, adj, informTime);
//     }
    
//     int dfs(int head, unordered_map<int, vector<int>>& adj, vector<int>& informTime) {
//         if (adj[head].empty()) {
//             return 0;
//         }
//         int max_time = 0;
//         for (int& sub : adj[head]) {
//             max_time = max(max_time, dfs(sub, adj, informTime));
//         }
//         return max_time + informTime[head];
//     }
// };