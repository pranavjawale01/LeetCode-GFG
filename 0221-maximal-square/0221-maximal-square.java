class Solution {
    int row, col;
    int[][] dp;

    public int solve(char[][] matrix, int i, int j) {
        if (i < 0 || j < 0 || i >= row || j >= col || matrix[i][j] == '0') {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 1;
        ans += Math.min(solve(matrix, i - 1, j - 1), Math.min(solve(matrix, i - 1, j), solve(matrix, i, j - 1)));
        return dp[i][j] = ans;
    }

    public int maximalSquare(char[][] matrix) {
        row = matrix.length;
        col = matrix[0].length;
        dp = new int[row][col];
        for (int[] arr : dp) {
            Arrays.fill(arr, -1);
        }
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans = Math.max(ans, solve(matrix, i, j));
            }
        }
        return ans * ans;
    }
}


// class Solution {
//     public int maximalSquare(char[][] matrix) {
//         int row = matrix.length, col = matrix[0].length;
//         int[][] dp = new int[row+1][col+1];
//         int ans = 0;
//         for (int i = 1; i <= row; i++) {
//             for (int j = 1; j <= col; j++) {
//                 if (matrix[i-1][j-1] == '1') {
//                     dp[i][j] = 1 + Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1]));
//                     ans = Math.max(ans, dp[i][j]);
//                 }
//             }
//         }
//         return ans * ans;
//     }
// }