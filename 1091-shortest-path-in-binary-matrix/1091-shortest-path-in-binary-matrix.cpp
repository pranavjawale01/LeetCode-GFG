class Solution {
public:
    vector<vector<int>> dirs = {{1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) {
            return -1;
        }
        
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dp[0][0] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (auto dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int dist = 1;
                if (isSafe(x_, y_) && grid[x_][y_] == 0 && d + dist < dp[x_][y_]) {
                    pq.push({d + dist, {x_, y_}});
                    dp[x_][y_] = d + dist;
                    grid[x_][y_] = 1;
                }
            }
        }

        return dp[n-1][m-1] == INT_MAX ? -1 : dp[n-1][m-1] + 1;
    }
};





// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
//             return -1;
//         }
//         queue<pair<int, int>> q;
//         q.push({0, 0});
//         int level = 1;
//         grid[0][0] = 1;
//         while (!q.empty()) {
//             int len = q.size();
//             while (len--) {
//                 pair<int, int> temp = q.front();
//                 q.pop();
//                 if (temp.first == n - 1 && temp.second == n - 1) {
//                     return level;
//                 }
//                 for (int i = -1; i <= 1; i++) {
//                     for (int j = -1; j <= 1; j++) {
//                         int x = temp.first + i;
//                         int y = temp.second + j;
//                         if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 0) {
//                             continue;
//                         }
//                         q.push({x, y});
//                         grid[x][y] = 1;
//                     }
//                 }
//             }
//             level++;
//         }
//         return -1;
//     }
// };