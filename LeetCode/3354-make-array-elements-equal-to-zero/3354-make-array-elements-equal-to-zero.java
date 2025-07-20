class Solution {
    public boolean solve(int[] nums, int i, int dir) {
        int n = nums.length;
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

    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (solve(nums.clone(), i, -1)) ans++;
                if (solve(nums.clone(), i, 1)) ans++;
            }
        }
        return ans;
    }
}