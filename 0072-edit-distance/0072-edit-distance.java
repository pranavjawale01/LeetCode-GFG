class Solution {
    private int[][] memo = new int[501][501];
    private int m, n;
    public int solve(String s1, String s2, int i, int j) {
        if (i == m) {
            return n - j;
        } else if (j == n) {
            return m - i;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (s1.charAt(i) == s2.charAt(j)) {
            return memo[i][j] = solve(s1, s2, i+1, j+1);
        } else {
            int ins = 1 + solve(s1, s2, i, j+1);
            int del = 1 + solve(s1, s2, i+1, j);
            int rep = 1 + solve(s1, s2, i+1, j+1);
            return memo[i][j] = Math.min(ins, Math.min(del, rep));
        }
    }
    public int minDistance(String word1, String word2) {
        m = word1.length();
        n = word2.length();
        for (int i = 0; i < m; i++) {
            Arrays.fill(memo[i], -1);
        }
        return solve(word1, word2, 0, 0);
    }
}