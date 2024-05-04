class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = nums[0];
        int n = nums.size();
        if (n == 1) {
            return true;
        }
        for (int i = 1; i < n; i++) {
            if (maxReach >= n - 1) {
                return true;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return false;
    }
};


// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> dp(n, false);
//         dp[0] = true;
//         for (int i = 1; i < n; i++) {
//             for (int j = i - 1; j >= 0; j--) {
//                 if (dp[j] == true && j + nums[j] >= i) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[n - 1];
//     }
// };


// class Solution {
// public:
//     bool solve(vector<int>& nums, int index, vector<int> &dp) {
//         if (index >= nums.size() - 1) {
//             return true;
//         }
//         if (dp[index] != -1) {
//             return dp[index];
//         }
//         int curr = nums[index];
//         while (curr > 0) {
//             if (solve(nums, index + curr, dp)) {
//                 return dp[index] = true;
//             }
//             curr--;
//         }
//         return dp[index] = false;
//     }
    
//     bool canJump(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return solve(nums, 0, dp);
//     }
// };