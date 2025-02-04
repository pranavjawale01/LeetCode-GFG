class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                sum += nums[i];
                ans = max(ans, sum);
            } else {
                sum = nums[i];
            }
        }
        return ans;
    }
};