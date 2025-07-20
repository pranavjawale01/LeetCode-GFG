class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        res[0][0] = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currCost = curr[0], i = curr[1], j = curr[2];
            if (res[i][j] < currCost) {
                continue;
            }
            for (int dir = 0; dir < 4; dir++) {
                int x = i + dirs[dir][0];
                int y = j + dirs[dir][1];
                if (x >= 0 && y >= 0 && x < m && y < n) {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir - 1 != dir) ? 1 : 0);
                    int newCost = currCost + dirCost;
                    if (newCost < res[x][y]) {
                        res[x][y] = newCost;
                        pq.push({newCost, x, y});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};





// TLE
// class Solution {
// public:
//     vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     int m, n;
//     vector<vector<bool>> vis;

//     int dfs(int i, int j, vector<vector<int>> &grid, int cost) {
//         if (i == m - 1 && j == n - 1) {
//             return cost;
//         }
//         vis[i][j] = true;
//         int minCost = INT_MAX;
//         for (int dir = 0; dir < 4; dir++) {
//             int x = i + dirs[dir][0];
//             int y = j + dirs[dir][1];
//             if (x >= 0 && y >= 0 && x < m && y < n && !vis[x][y]) {
//                 int nextCost = cost + ((grid[i][j] - 1 != dir) ? 1 : 0);
//                 minCost = min(minCost, dfs(x, y, grid, nextCost));
//             }
//         }
//         vis[i][j] = false;
//         return minCost;
//     }

//     int minCost(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         vis.resize(m, vector<bool>(n, false));
//         return dfs(0, 0, grid, 0);
//     }
// };