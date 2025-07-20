class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int rows = grid.length , cols = grid[0].length;
        
        int[] oneRow = new int[rows];
        int[] oneCol = new int[cols];
        int[] zeroRow = new int[rows];
        int[] zeroCol = new int[cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    zeroRow[i]++;
                    zeroCol[j]++;
                } else if (grid[i][j] == 1) {
                    oneRow[i]++;
                    oneCol[j]++;
                }
            }
        }
        
        int[][] matrix = new int[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }
        
        return matrix;
    }
}