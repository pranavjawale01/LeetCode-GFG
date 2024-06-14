class Solution {
public:
    int row, col;
    void bfs(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 1;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && ny >= 0 && nx < row && ny < col && grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    if (grid[i][j] == 0) {
                        bfs(grid, i, j);
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};



// class Solution {
// public:
//     int row, col;
//     void dfs(vector<vector<int>>& grid, int i, int j) {
//         if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 1) {
//             return;
//         }
//         grid[i][j] = 1;
//         dfs(grid, i+1, j);
//         dfs(grid, i-1, j);
//         dfs(grid, i, j+1);
//         dfs(grid, i, j-1);
//     }
//     int closedIsland(vector<vector<int>>& grid) {
//         row = grid.size(), col = grid[0].size();
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
//                     if (grid[i][j] == 0) {
//                         dfs(grid, i, j);
//                     }
//                 }
//             }
//         }
//         int count = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 0) {
//                     dfs(grid, i, j);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };