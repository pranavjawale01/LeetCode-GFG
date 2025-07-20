class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> count(n, 0);
        
        for (int num : nums) {
            count[num] += num;
        }
        
        vector<int> dp(n, 0);
        dp[1] = count[1];
        for (int i = 2; i < n; i++) {
            dp[i] = max(count[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
    }
};