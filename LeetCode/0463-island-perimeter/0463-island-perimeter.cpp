class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int peri = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    if (j+1 == col || grid[i][j+1] == 0) {
                        peri++;
                    }
                    if (j-1 < 0 || grid[i][j-1] == 0) {
                        peri++;
                    }
                    if (i-1 < 0 || grid[i-1][j] == 0) {
                        peri++;
                    }
                    if (i+1 == row || grid[i+1][j] == 0) {
                        peri++;
                    }
                }
            }
        }
        return peri;
    }
};

// class Solution {
// public:
//     int bfs(vector<vector<int>>& grid, int i, int j, int row, int col) {
//         int peri = 0;
//         queue<pair<int, int>> q;
//         q.push({i, j});
//         grid[i][j] = -1;
//         vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//         while (!q.empty()) {
//             auto it = q.front();
//             q.pop();
//             for (auto &d : dir) {
//                 int i_ = it.first + d.first;
//                 int j_ = it.second + d.second;
//                 if (i_ < 0 || j_ < 0 || i_ >= row || j_ >= col || grid[i_][j_] == 0) {
//                     peri++;
//                 } else if (grid[i_][j_] == -1) {
//                     continue;
//                 } else {
//                     q.push({i_, j_});
//                     grid[i_][j_] = -1;
//                 }
//             }
//         }
//         return peri;
//     }
    
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1) {
//                     return bfs(grid, i, j, row, col);
//                 }
//             }
//         }
//         return 0;
//     }
// };

// class Solution {
// public:
//     void solve(vector<vector<int>>& grid, int i, int j, int &row, int &col, int &peri) {
//         if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
//             peri++;
//             return;
//         }
//         if (grid[i][j] == -1) {
//             return;
//         }
//         grid[i][j] = -1;
//         solve(grid, i+1, j, row, col, peri);
//         solve(grid, i-1, j, row, col, peri);
//         solve(grid, i, j+1, row, col, peri);
//         solve(grid, i, j-1, row, col, peri);
//     }
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();
//         int peri = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == 1) { 
//                     solve(grid, i, j, row, col, peri);
//                     return peri;
//                 }
//             }
//         }
//         return 0;
//     }
// };