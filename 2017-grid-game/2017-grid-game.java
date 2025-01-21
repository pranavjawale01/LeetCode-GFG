class Solution {
    public long gridGame(int[][] grid) {
        int n = grid[0].length;
        long firstRowSum = 0;
        for (int i = 0; i < n; i++) {
            firstRowSum += grid[0][i];
        }

        long secondRowSum = 0;
        long minRob2Sum = Long.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            firstRowSum -= grid[0][i];
            minRob2Sum = Math.min(minRob2Sum, Math.max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][i];
        }

        return minRob2Sum;
    }
}