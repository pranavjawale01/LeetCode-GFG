class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        vector<unordered_map<long long, int>> dp(n);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j];
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                result += cnt;

                dp[i][diff] += cnt + 1;
            }
        }

        return result;
    }
};