class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) dp[i] = dp[i+1] + 1;
        }
        int ans = 0;
        int low = 1, high = n / 2;
        while (low <= high) {
            bool flag = false;
            int mid = low + (high - low) / 2;
            for (int i = 0; i <= n - 2 * mid; i++) {
                if (dp[i] >= mid && dp[i + mid] >= mid) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                low = mid + 1;
                ans = max(ans, mid);
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};