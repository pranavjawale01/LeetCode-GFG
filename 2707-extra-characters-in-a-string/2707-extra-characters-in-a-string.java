class Solution {
    int[] dp;
    
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        dp = new int[n + 1];
        Arrays.fill(dp, -1);
        
        Set<String> st = new HashSet<>(Arrays.asList(dictionary));
        
        return solve(0, s, st, n);
    }
    
    private int solve(int i, String s, Set<String> st, int n) {
        if (i >= n) {
            return 0;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }

        int result = 1 + solve(i + 1, s, st, n);

        for (int j = i; j < n; j++) {
            String curr = s.substring(i, j + 1);
            
            if (st.contains(curr)) {
                result = Math.min(result, solve(j + 1, s, st, n));
            }
        }

        dp[i] = result;
        return result;
    }
}