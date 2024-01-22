class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        
        int dup = -1, missing = -1;
        
        for (int i = 0; i < n; i++) {
            int index = Math.abs(nums[i]) - 1;
            if (nums[index] < 0) {
                dup = Math.abs(nums[i]);
            } else {
                nums[index] *= -1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing = i + 1;
            }
        }
        
        return new int[]{dup, missing};
    }
}