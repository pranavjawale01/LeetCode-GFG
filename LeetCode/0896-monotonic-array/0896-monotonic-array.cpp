class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int order = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                if (order == 0) {
                    order = 1;
                } else if (order == -1) {
                    return false;
                }
            } else if (nums[i] < nums[i-1]) {
                if (order == 0) {
                    order = -1;
                } else if (order == 1) {
                    return false;
                }
            }
        }
        return true;
    }
};