class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int ans1 = 0, ans2 = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col / 2; ++j) {
                if (grid[i][j] != grid[i][col - 1 - j]) {
                    ans1++;
                }
            }
        }
        for (int j = 0; j < col; ++j) {
            for (int i = 0; i < row / 2; ++i) {
                if (grid[i][j] != grid[row - 1 - i][j]) {
                    ans2++;
                }
            }
        }
    
        return min(ans1, ans2);
    }
};