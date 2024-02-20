class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) {
            return 0;
        }
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] + 1 != nums[i+1]) {
                return i+1;
            }
        }
        return n;
    }
};