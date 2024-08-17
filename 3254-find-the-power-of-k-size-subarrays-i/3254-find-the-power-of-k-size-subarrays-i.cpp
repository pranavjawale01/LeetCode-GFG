class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> ans(n-k+1, -1);
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
};





// class Solution {
// public:
//     vector<int> resultsArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans(n - k + 1, -1);
//         for (int i = 0; i < n - k  + 1; i++) {
//             bool flag = true;
//             for (int j = i; j < i + k - 1; j++) {
//                 if (nums[j] != nums[j+1] - 1) {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag) {
//                 ans[i] = nums[i+k-1];
//             }
//         }
//         return ans;
//     }
// };