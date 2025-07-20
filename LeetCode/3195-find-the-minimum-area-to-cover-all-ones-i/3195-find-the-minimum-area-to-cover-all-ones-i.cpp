class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int minRow = row, maxRow = -1;
        int minCol = col, maxCol = -1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    minCol = min(minCol, j);
                    maxRow = max(maxRow, i);
                    maxCol = max(maxCol, j);
                }
            }
        }
        if (minRow == row || minCol == col || maxRow == -1 || maxCol == -1) {
            return 0;
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};