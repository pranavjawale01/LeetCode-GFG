class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;
        
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int a = Integer.MAX_VALUE, b = Integer.MAX_VALUE;
                if (j - 1 >= 0) {
                    a = matrix[i-1][j-1];
                }
                if (j + 1 < col) {
                    b = matrix[i-1][j+1];
                }
                matrix[i][j] += Math.min(Math.min(matrix[i-1][j], a), b);
            }
        }
        
        int result = Integer.MAX_VALUE;
        
        for (int i = 0; i < col; i++) {
            result = Math.min(result, matrix[row - 1][i]);
        }
        return result;
    }
}