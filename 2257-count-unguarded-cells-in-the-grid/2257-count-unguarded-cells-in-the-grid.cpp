class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols, int direction) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 1 || grid[row][col] == 2) {
            return;
        }
        grid[row][col] = 3;
        if (direction == 1) {
            dfs(grid, row - 1, col, rows, cols, direction);
        } else if (direction == 2) {
            dfs(grid, row + 1, col, rows, cols, direction);
        } else if (direction == 3) {
            dfs(grid, row, col - 1, rows, cols, direction);
        } else {
            dfs(grid, row, col + 1, rows, cols, direction);
        }
    }

    int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 1;
        }
        for (const auto& guard : guards) {
            int guardRow = guard[0];
            int guardCol = guard[1];
            dfs(grid, guardRow - 1, guardCol, rows, cols, 1);
            dfs(grid, guardRow + 1, guardCol, rows, cols, 2);
            dfs(grid, guardRow, guardCol - 1, rows, cols, 3);
            dfs(grid, guardRow, guardCol + 1, rows, cols, 4);
        }
        int unguardedCount = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    ++unguardedCount;
                }
            }
        }
        return unguardedCount;
    }
};










// class Solution {
// public:
//     int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//         vector<vector<int>> grid(m, vector<int>(n, 0));
//         for (const auto &wall : walls) {
//             grid[wall[0]][wall[1]] = 1;
//         }        
//         for (const auto &guard : guards) {
//             grid[guard[0]][guard[1]] = 2;
//         }        
//         for (const auto &guard : guards) {
//             int x = guard[0], y = guard[1];
//             for (const auto &dir : directions) {
//                 int nx = x + dir.first, ny = y + dir.second;
//                 while (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 1 && grid[nx][ny] != 2) {
//                     if (grid[nx][ny] == 0) {
//                         grid[nx][ny] = 3;
//                     }
//                     nx += dir.first;
//                     ny += dir.second;
//                 }
//             }
//         }
//         int count = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };







// TLE
// class Solution {
// public:
//     void solve(int i, int j, int m, int n, vector<vector<int>> &arr) {
//         for (int k = j + 1; k < n && arr[i][k] != 1; k++) arr[i][k] = 2;
//         for (int k = j - 1; k >= 0 && arr[i][k] != 1; k--) arr[i][k] = 2;
//         for (int k = i + 1; k < m && arr[k][j] != 1; k++) arr[k][j] = 2;
//         for (int k = i - 1; k >= 0 && arr[k][j] != 1; k--) arr[k][j] = 2;
//     }

//     int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         vector<vector<int>> arr(m, vector<int>(n, 0));
//         for (auto &wall : walls) {
//             int x = wall[0], y = wall[1];
//             arr[x][y] = 1;
//         }
//         for (auto &guard : guards) {
//             int x = guard[0], y = guard[1];
//             arr[x][y] = 2;
//             solve(x, y, m, n, arr);
//         }
//         for (auto &guard : guards) {
//             int x = guard[0], y = guard[1];
//             solve(x, y, m, n, arr);
//         }
//         int count = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (arr[i][j] == 0) count++;
//             }
//         }
//         return count;
//     }
// };