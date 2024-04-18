class Solution {
public:
    void solve(vector<vector<int>>& grid, int i, int j, int &row, int &col, int &peri) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
            peri++;
            return;
        }
        if (grid[i][j] == -1) {
            return;
        }
        grid[i][j] = -1;
        solve(grid, i+1, j, row, col, peri);
        solve(grid, i-1, j, row, col, peri);
        solve(grid, i, j+1, row, col, peri);
        solve(grid, i, j-1, row, col, peri);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int peri = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) { 
                    solve(grid, i, j, row, col, peri);
                    return peri;
                }
            }
        }
        return 0;
    }
};