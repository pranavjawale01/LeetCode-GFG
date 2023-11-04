class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int target = 1;
        auto it = find(nums.begin(), nums.end(), target);
        if (it == nums.end()) {
            return 1;
        }
        sort(nums.begin(),nums.end());
        int smallestNonNegative = INT_MAX;
        int smallestNonNegativeIndex = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num >= 0 && num < smallestNonNegative) {
                smallestNonNegative = num;
                smallestNonNegativeIndex = i;
            }
        }
        int low = smallestNonNegativeIndex, high = nums.size() - 1;
        int i = low;
        for (i = low; i < high; i++) {
            if (nums[i] + 1 == nums[i + 1]) {
                continue;
            } else {
                return nums[i] + 1;
            }
        }
        return i+1;
    }
};
*/