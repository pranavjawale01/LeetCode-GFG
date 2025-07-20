class Solution {
public:
    void bfs(vector<vector<int>>& grid, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int x = cell.first;
            int y = cell.second;
            
            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
                    grid[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    if (grid[i][j] == 1) {
                        bfs(grid, i, j);
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};



// class Solution {
// public:
//     void dfs(vector<vector<int>>& grid, int i, int j) {
//         if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1) {
//             return;
//         }
//         grid[i][j] = 0;
//         dfs(grid, i+1, j);
//         dfs(grid, i-1, j);
//         dfs(grid, i, j+1);
//         dfs(grid, i, j-1);
//     }
//     int numEnclaves(vector<vector<int>>& grid) {
//         int row = grid.size(), col = grid[0].size();
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
//                     if (grid[i][j] == 1) {
//                         dfs(grid, i, j);
//                     }
//                 }
//             }
//         }
//         int count = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };