class Solution {
    public int minimumOperations(int[] nums) {
        int count = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int rem = nums[i] % 3;
            if (rem == 1) {
                count++;
            } else if (rem == 2) {
                count++;
            }
        }
        return count;
    }
}