class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool bfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        bool ans = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid2[i][j] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (grid1[x][y] == 0) {
                ans = false;
            }
            for (auto dir : dirs) {
                int newx = x + dir[0];
                int newy = y + dir[1];
                if (newx >= 0 && newx < row && newy >= 0 && newy < col && grid2[newx][newy] == 1) {
                    grid2[newx][newy] = 0;
                    q.push({newx, newy});
                }
            }
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        row = grid1.size();
        col = grid1[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid2[i][j] == 1 && bfs(i, j, grid1, grid2)) {
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
//     vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//     bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         if (i < 0 || j < 0 || i >= row || j >= col) {
//             return true;
//         }
//         if (grid2[i][j] == 0) {
//             return true;
//         }
//         grid2[i][j] = 0;
//         bool ans = grid1[i][j] == 1;
//         for (auto dir : dirs) {
//             int x = dir[0] + i;
//             int y = dir[1] + j;
//             ans = ans & dfs(x, y, grid1, grid2);
//         }
//         return ans;
//     }
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         row = grid1.size();
//         col = grid1[0].size();
//         int count = 0;
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (grid2[i][j] == 1 && dfs(i, j, grid1, grid2)) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };