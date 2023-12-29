class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int count = n;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
                for (int j = i; j < n -1; j++) {
                    nums[j] = nums[j+1];
                }
                i--;
                n--;
                count--;
            }
        }
        return count;
    }
}