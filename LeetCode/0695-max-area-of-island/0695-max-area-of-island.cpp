class Solution {
public:
    int row, col;
    int bfs(vector<vector<int>> &grid, int i, int j) {
        queue<pair<int, int>> q;
        grid[i][j] = 0;
        q.push({i, j});
        int area = 1;

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (const auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
                    grid[nx][ny] = 0;
                    area++;
                    q.push({nx, ny});
                }
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, bfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};





// class Solution {
// public:
//     int row, col;
//     int dfs(vector<vector<int>> &grid, int i, int j) {
//         if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0) {
//             return 0;
//         }
//         grid[i][j] = 0;
//         return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
//     }
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         row = grid.size();
//         col = grid[0].size();
//         int ans = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1) {
//                     ans = max(ans, dfs(grid, i, j));
//                 }
//             }
//         }
//         return ans;
//     }
// };