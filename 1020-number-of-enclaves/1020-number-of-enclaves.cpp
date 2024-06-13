class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i, j);
        dfs(grid, i, j);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    if (grid[i][j] == 1) {
                        dfs(grid, i, j);
                    }
                }
            }
        }
    }
};