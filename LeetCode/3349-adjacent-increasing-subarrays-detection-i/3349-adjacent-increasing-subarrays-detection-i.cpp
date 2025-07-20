class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;
        for (int i = 0; i <= n - 2 * k; i++) {
            bool first = true, second = true;
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    first = false;
                    break;
                }
            }
            if (first) {
                for (int j = i + k; j < i + 2 * k - 1; j++) {
                    if (nums[j] >= nums[j + 1]) {
                        second = false;
                        break;
                    }
                }
            }
            if (first && second) return true;
        }
        return false;
    }
};