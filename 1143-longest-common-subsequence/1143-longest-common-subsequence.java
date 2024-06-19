class Solution {
    private int[][] t;

    public int LCS(String s1, String s2, int m, int n) {
        if (m == 0 || n == 0)
            return t[m][n] = 0;

        if (t[m][n] != -1)
            return t[m][n];

        if (s1.charAt(m - 1) == s2.charAt(n - 1))
            return t[m][n] = 1 + LCS(s1, s2, m - 1, n - 1);

        return t[m][n] = Math.max(LCS(s1, s2, m, n - 1), LCS(s1, s2, m - 1, n));
    }

    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        t = new int[m + 1][n + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        return LCS(text1, text2, m, n);
    }
}