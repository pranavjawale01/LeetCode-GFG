class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, int row, int col) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            for (auto& dir : direction) {
                int i_ = it.first + dir.first;
                int j_ = it.second + dir.second;
                if (i_ < 0 || j_ < 0 || i_ >= row || j_ >= col || grid[i_][j_] == '0') {
                    continue;
                } else {
                    q.push({i_, j_});
                    grid[i_][j_] = '0';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, row, col);
                    count++;
                }
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     void dfs(vector<vector<char>>& grid, int i, int j, int row, int col) {
//         if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0') {
//             return;
//         }
//         grid[i][j] = '0';
//         dfs(grid, i+1, j, row, col);
//         dfs(grid, i-1, j, row, col);
//         dfs(grid, i, j+1, row, col);
//         dfs(grid, i, j-1, row, col);
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int count = 0;
//         int row = grid.size(), col = grid[0].size();
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid[i][j] == '1') {
//                     dfs(grid, i, j, row, col);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };