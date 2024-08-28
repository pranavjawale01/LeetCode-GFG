class Solution {
public:
    int row, col;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if (i < 0 || j < 0 || i >= row || j >= col) {
            return true;
        }
        if (grid2[i][j] == 0) {
            return true;
        }
        grid2[i][j] = 0;
        bool ans = grid1[i][j] == 1;
        for (auto dir : dirs) {
            int x = dir[0] + i;
            int y = dir[1] + j;
            ans = ans & dfs(x, y, grid1, grid2);
        }
        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        row = grid1.size();
        col = grid1[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid2[i][j] == 1 && dfs(i, j, grid1, grid2)) {
                    count++;
                }
            }
        }
        return count;
    }
};