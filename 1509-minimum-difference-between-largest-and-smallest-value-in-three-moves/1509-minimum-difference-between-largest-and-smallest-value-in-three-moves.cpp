class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 3; i < n; i++) {
            nums[i] = nums[0];
        }
        sort(nums.begin(), nums.end());
        return nums[n-1] - nums[0];
    }
};