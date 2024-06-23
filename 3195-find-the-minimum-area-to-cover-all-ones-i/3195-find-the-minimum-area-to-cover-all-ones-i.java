class Solution {
    public int minimumArea(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int minRow = row, maxRow = -1;
        int minCol = col, maxCol = -1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    minRow = Math.min(minRow, i);
                    minCol = Math.min(minCol, j);
                    maxRow = Math.max(maxRow, i);
                    maxCol = Math.max(maxCol, j);
                }
            }
        }
        if (minRow == row || minCol == col || maxRow == -1 || maxCol == -1) {
            return 0;
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
}