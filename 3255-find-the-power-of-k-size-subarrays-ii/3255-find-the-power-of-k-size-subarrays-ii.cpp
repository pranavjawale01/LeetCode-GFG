class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 1), ans(n - k + 1, -1);
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                dp[i] = 1 + dp[i-1];
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