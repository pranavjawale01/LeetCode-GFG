class Solution {
    public boolean solve(int i, int currSum, String s, int num, int[][] dp) {
        if (i == s.length()) {
            return currSum == num;
        }
        if (currSum > num) return false;
        if (dp[i][currSum] != -1) {
            return dp[i][currSum] == 1;
        }
        boolean flag = false;
        for (int j = i; j < s.length(); j++) {
            String currStr = s.substring(i, j+1);
            int added = Integer.parseInt(currStr);
            flag |= solve(j+1, currSum + added, s, num, dp);
            if (flag) {
                dp[i][currSum] = 1;
                return true;
            }
        }
        dp[i][currSum] = 0;
        return false;
    }
    public int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            String s = Integer.toString(sq);
            int[][] dp = new int[s.length()][i+1];
            for (int[] row : dp) {
                Arrays.fill(row, -1);
            }
            if (solve(0, 0, s, i, dp)) {
                ans += sq;
            }
        }
        return ans;
    }
}