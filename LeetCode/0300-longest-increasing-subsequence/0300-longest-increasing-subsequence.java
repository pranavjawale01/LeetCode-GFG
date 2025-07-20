class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int maxL = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    maxL = Math.max(maxL, dp[i]);
                }
            }
        }
        return maxL;
    }
}



// class Solution {
//     private int n;
//     private int[][] dp = new int[2501][2501];
//     public int solve(int[] nums, int i, int p) {
//         if (i >= n) {
//             return 0;
//         }
//         if (p != -1 && dp[i][p] != -1) {
//             return dp[i][p];
//         }
//         int take = 0;
//         if (p == -1 || nums[i] > nums[p]) {
//             take = 1 + solve(nums, i+1, i); 
//         }
//         int skip = solve(nums, i+1, p);
//         if (p != -1) {
//             dp[i][p] = Math.max(take, skip);
//         }
//         return Math.max(take, skip);
//     }
//     public int lengthOfLIS(int[] nums) {
//         n = nums.length;
//         for (int i = 0; i < n; i++) {
//             Arrays.fill(dp[i], -1);
//         }
//         return solve(nums, 0, -1);
//     }
// }



// class Solution {
//     public int lengthOfLIS(int[] nums) {
//         int size = 0;
//         for (int x : nums) {
//             int i = 0, j = size;
//             while (i != j) {
//                 int n = (i + j) / 2;
//                 if (nums[n] < x) {
//                     i = n + 1;
//                 } else {
//                     j = n;
//                 }
//             }
//             nums[i] = x;
//             if (i == size) {
//                 size++;
//             }
//         }
//         return size;
//     }
// }