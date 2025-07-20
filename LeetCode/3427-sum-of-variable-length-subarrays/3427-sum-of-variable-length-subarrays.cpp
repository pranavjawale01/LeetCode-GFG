class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int s = max(0, i - nums[i]);
            for (int j = s; j <= i; j++) {
                ans += nums[j];
            }
        }
        return ans;
    }
};