class Solution {
public:
    #define p pair<int, pair<int, int>>
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            int time = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if (i == m - 1 && j == n - 1) return time;
            if (vis[i][j]) continue;
            vis[i][j] = true;
            for (auto x : dirs) {
                int r = i + x[0];
                int c = j + x[1];
                if (r < 0 || r >= m || c < 0 || c >= n || vis[r][c]) continue;
                if (grid[r][c] <= time + 1) {
                    pq.push({time + 1, {r, c}});
                } else if ((grid[r][c] - time) % 2 == 0) {
                    pq.push({grid[r][c] + 1, {r, c}});
                } else {
                    pq.push({grid[r][c], {r, c}});
                }
            }
        }
        return -1;
    }
};









// TLE
// class Solution {
// public:
//     #define p pair<int, int>
//     int minimumTime(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         queue<p> q;
//         q.push({0, 0});
//         vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//         int time = 1;
//         while (!q.empty()) {
//             int len = q.size();
//             while (len--) {
//                 auto curr = q.front();
//                 q.pop();
//                 int i = curr.first;
//                 int j = curr.second;
//                 if (((i + 1) == n) && ((j + 1) == m)) return time - 1;
//                 for (auto x : dirs) {
//                     int xi = i + x[0];
//                     int yj = j + x[1];
//                     if (xi >= 0 && xi < n && yj >= 0 && yj < m) {
//                         if (grid[xi][yj] <= time) {
//                             q.push({xi, yj});
//                         }
//                     }
//                 }
//             }
//             time++;
//         }
//         return -1;
//     }
// };