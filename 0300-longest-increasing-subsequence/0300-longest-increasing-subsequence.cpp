class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxL = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxL = max(maxL, dp[i]);
                }
            }
        }
        return maxL;
    }
};



// class Solution {
// public:
//     int n;
//     int dp[2501][2501];
//     int solve(vector<int> &nums, int i, int p) {
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
//             dp[i][p] = max(take, skip);
//         }
//         return max(take, skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         memset(dp, -1, sizeof(dp));
//         n = nums.size();
//         return solve(nums, 0, -1);
//     }
// };



// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> tails(nums.size(), 0);
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
// };