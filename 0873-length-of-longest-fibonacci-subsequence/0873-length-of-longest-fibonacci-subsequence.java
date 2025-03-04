class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        Map<Integer, Integer> map = new HashMap<>();
        int[][] dp = new int[n][n];
        for (int[] row : dp) Arrays.fill(row, 2);
        for (int i = 0; i < n; i++) map.put(arr[i], i);
        int maxLen = 0;

        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int target = arr[k] - arr[j];
                if (map.containsKey(target) && map.get(target) < j) {
                    int i = map.get(target);
                    dp[j][k] = dp[i][j] + 1;
                }
                maxLen = Math.max(maxLen, dp[j][k]);
            }
        }
        return maxLen >= 3 ? maxLen : 0;
    }
}













// class Solution {
//     private Map<Integer, Integer> map;
//     private int[][] dp;

//     private int solve(int i, int j, int[] arr) {
//         if (dp[i][j] != -1) return dp[i][j];
//         int target = arr[j] - arr[i];
//         if (map.containsKey(target) && map.get(target) < i) {
//             int k = map.get(target);
//             dp[i][j] = solve(k, i, arr) + 1;
//             return dp[i][j];
//         }
//         return dp[i][j] = 2;
//     }

//     public int lenLongestFibSubseq(int[] arr) {
//         int n = arr.length;
//         dp = new int[n][n];
//         for (int[] row : dp) Arrays.fill(row, -1);
//         map = new HashMap<>();
//         for (int i = 0; i < n; i++) map.put(arr[i], i);
//         int maxLen = 0;
//         for (int i = 1; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int len = solve(i, j, arr);
//                 if (len >= 3) {
//                     maxLen = Math.max(maxLen, len);
//                 }
//             }
//         }
//         return maxLen >= 3 ? maxLen : 0;
//     }
// }