class Solution {
    private int[][] dp = new int[201][201];
    
    private int solve(List<List<Integer>> triangle, int n, int index, int level) {
        if (level >= n) {
            return 0;
        }
        if (dp[level][index] != -1) {
            return dp[level][index];
        }
        return dp[level][index] = triangle.get(level).get(index) + Math.min(solve(triangle, n, index, level + 1), solve(triangle, n, index + 1, level + 1));
    }
    
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int i = 0; i < 201; i++) {
            Arrays.fill(dp[i], -1);
        }
        int n = triangle.size();
        return solve(triangle, n, 0, 0);
    }
}