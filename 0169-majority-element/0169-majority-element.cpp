class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0], count = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (count == 0) {
                element = nums[i];
                count++;
            } else if (nums[i] == element) {
                count++;
            } else {
                count--;
            }
        }
        return element;
    }
};