public class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        if (n == 0 || s.charAt(0) == '0') {
            return 0;
        }

        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            if (s.charAt(i - 1) != '0') {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && isValidMapping(s.charAt(i - 2), s.charAt(i - 1))) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

    private boolean isValidMapping(char a, char b) {
        int num = (a - '0') * 10 + (b - '0');
        return num >= 10 && num <= 26;
    }
}