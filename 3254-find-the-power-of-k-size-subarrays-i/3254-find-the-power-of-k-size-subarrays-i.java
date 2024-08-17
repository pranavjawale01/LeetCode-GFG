class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int[] ans = new int[n-k+1];
        Arrays.fill(ans, -1);
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                dp[i] = dp[i-1] + 1;
            }
        }
        for (int i = k - 1, j = 0; i < n; i++, j++) {
            if (dp[i] >= k) {
                ans[j] = nums[i];
            }
        }
        return ans;
    }
}





// class Solution {
//     public int[] resultsArray(int[] nums, int k) {
//         int n = nums.length;
//         int[] ans = new int[n - k + 1];
//         for (int i = 0; i < n - k  + 1; i++) {
//             boolean flag = true;
//             for (int j = i; j < i + k - 1; j++) {
//                 if (nums[j] != nums[j+1] - 1) {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag) {
//                 ans[i] = nums[i+k-1];
//             } else {
//                 ans[i] = -1;
//             }
//         }
//         return ans;
//     }
// }