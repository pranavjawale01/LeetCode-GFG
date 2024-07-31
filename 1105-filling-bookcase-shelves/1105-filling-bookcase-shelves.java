class Solution {
    private int n;
    private int WIDTH;
    private int[][] dp = new int[1001][1001];
    private int solve(int[][] books, int i, int remain, int maxHt) {
        if (i >= n) {
            return maxHt;
        }
        if (dp[i][remain] != -1) {
            return dp[i][remain];
        }
        int bookW = books[i][0];
        int bookH = books[i][1];
        int keep = Integer.MAX_VALUE, skip = Integer.MAX_VALUE;
        if (bookW <= remain) {
            keep = solve(books, i+1, remain - bookW, Math.max(maxHt, bookH));
        }
        skip = maxHt + solve(books, i+1, WIDTH - bookW, bookH);
        return dp[i][remain] = Math.min(keep, skip);
    }
    public int minHeightShelves(int[][] books, int shelfWidth) {
        n = books.length;
        WIDTH = shelfWidth;
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(books, 0, shelfWidth, 0);
    }
}