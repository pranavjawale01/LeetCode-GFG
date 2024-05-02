class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            if ((nums[low] * (-1)) == nums[high]) {
                return nums[high];
            } else if ((nums[low] * (-1)) < nums[high]) {
                high--;
            } else if ((nums[low] * (-1)) > nums[high]) {
                low++;
            }
        }
        return -1;
    }
};