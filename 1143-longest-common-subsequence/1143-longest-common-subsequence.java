class Solution {
    private int[][] memory;

    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        memory = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            Arrays.fill(memory[i], -1);
        }

        return solve(text1, text2, 0, 0);
    }

    private int solve(String s1, String s2, int i, int j) {
        if (i >= s1.length() || j >= s2.length()) {
            return 0;
        }

        if (memory[i][j] != -1) {
            return memory[i][j];
        }

        if (s1.charAt(i) == s2.charAt(j)) {
            return memory[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }

        return memory[i][j] = Math.max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }
}