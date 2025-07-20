class Solution {
public:
    int solve(vector<int>& nums, int index) {
        if (index >= nums.size() - 1) {
            return 0;
        }
        int count = INT_MAX - 1;
        for (int i = 1; i <= nums[index]; i++) {
            count = min(count, 1 + solve(nums, index + i));
        }
        return count;
    }
    
    int jump(vector<int>& nums) {
        return solve(nums, 0);
    }
};