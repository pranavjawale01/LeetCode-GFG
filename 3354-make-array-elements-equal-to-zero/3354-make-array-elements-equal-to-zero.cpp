class Solution {
public:
    bool solve(vector<int> nums, int i, int dir) {
        int n = nums.size();
        while (i >= 0 && i < n) {
            if (nums[i] == 0) {
                i += dir;
            } else {
                nums[i]--;
                dir = -dir;
                i += dir;
            }
        }
        for (int x : nums) {
            if (x != 0) return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (solve(nums, i, -1)) ans++;
                if (solve(nums, i, 1)) ans++;
            }
        }
        return ans;
    }
};