class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxsum = 0, minsum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            maxsum = max(nums[i], maxsum + nums[i]);
            minsum = min(nums[i], minsum + nums[i]);
            ans = max(ans, max(abs(maxsum), abs(minsum)));
        }
        return ans;
    }
};