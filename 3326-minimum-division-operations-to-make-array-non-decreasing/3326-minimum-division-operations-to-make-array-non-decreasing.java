class Solution {
    public int solve(int n1, int n2) {
        for (int i = n1; i > 1; i--) {
            if (n2 % i == 0) return i;
        }
        return -1;
    }
    public int minOperations(int[] nums) {
        int count = 0;
        for (int i = nums.length - 1; i > 0; i--) {
            if (nums[i] < nums[i-1]) {
                nums[i-1] = solve(nums[i], nums[i-1]);
                if (nums[i-1] == -1) return -1;
                count++;
            }
        }
        return count;
    }
}