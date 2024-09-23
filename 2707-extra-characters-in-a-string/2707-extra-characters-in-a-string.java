class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        Set<String> st = new HashSet<>(Arrays.asList(dictionary));
        int[] dp = new int[n+1];
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i+1];
            for (int j = i; j < n; j++) {
                String curr = s.substring(i, j + 1);
                if (st.contains(curr)) {
                    dp[i] = Math.min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
}







// class Solution {
//     int[] dp;
    
//     public int minExtraChar(String s, String[] dictionary) {
//         int n = s.length();
//         dp = new int[n + 1];
//         Arrays.fill(dp, -1);
        
//         Set<String> st = new HashSet<>(Arrays.asList(dictionary));
        
//         return solve(0, s, st, n);
//     }
    
//     private int solve(int i, String s, Set<String> st, int n) {
//         if (i >= n) {
//             return 0;
//         }
        
//         if (dp[i] != -1) {
//             return dp[i];
//         }

//         int result = 1 + solve(i + 1, s, st, n);

//         for (int j = i; j < n; j++) {
//             String curr = s.substring(i, j + 1);
            
//             if (st.contains(curr)) {
//                 result = Math.min(result, solve(j + 1, s, st, n));
//             }
//         }

//         dp[i] = result;
//         return result;
//     }
// }