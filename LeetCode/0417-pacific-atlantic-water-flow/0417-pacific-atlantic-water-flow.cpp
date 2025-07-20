class Solution {
public:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& reach) {
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& dir : directions) {
                int x = i + dir.first;
                int y = j + dir.second;
                if (x >= 0 && y >= 0 && x < m && y < n && !reach[x][y] && heights[x][y] >= heights[i][j]) {
                    reach[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty()) return result;

        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        for (int i = 0; i < m; i++) {
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, n - 1});
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
        }

        for (int j = 0; j < n; j++) {
            pacificQueue.push({0, j});
            atlanticQueue.push({m - 1, j});
            pacific[0][j] = true;
            atlantic[m - 1][j] = true;
        }

        bfs(heights, pacificQueue, pacific);
        bfs(heights, atlanticQueue, atlantic);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};





// class Solution {
// public:
//     int m, n;
//     vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//     void dfs(vector<vector<int>> &heights, vector<vector<bool>> &reach, int i, int j) {
//         reach[i][j] = true;
//         for (vector<int> &dir : dirs) {
//             int x = i + dir[0];
//             int y = j + dir[1];
//             if (x < 0 || y < 0 || x >= m || y >= n || reach[x][y] || heights[x][y] < heights[i][j]) {
//                 continue;
//             }
//             dfs(heights, reach, x, y);
//         }
//     }
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         m = heights.size();
//         n = heights[0].size();
//         vector<vector<bool>> pacific(m, vector<bool>(n, false));
//         vector<vector<bool>> atlantic(m, vector<bool>(n, false));
//         for (int i = 0; i < m; i++) {
//             dfs(heights, pacific, i, 0);
//             dfs(heights, atlantic, i, n - 1);
//         }
//         for (int j = 0; j < n; j++) {
//             dfs(heights, pacific, 0, j);
//             dfs(heights, atlantic, m-1, j);
//         }
//         vector<vector<int>> result;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (pacific[i][j] && atlantic[i][j]) {
//                     result.push_back({i, j});
//                 }
//             }
//         }
//         return result;
//     }
// };