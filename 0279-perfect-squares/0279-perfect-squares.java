class Solution {
    private int[] memo = new int[10001];
    public int solve(int n) {
        if (n == 0) {
            return 0;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int minCount = Integer.MAX_VALUE;
        for (int i = 1; i * i <= n; i++) {
            int result = 1 + solve(n - i*i);
            minCount = Math.min(minCount, result);
        }
        return memo[n] = minCount;
    }
    public int numSquares(int n) {
        Arrays.fill(memo, -1);
        return solve(n);
    }
}