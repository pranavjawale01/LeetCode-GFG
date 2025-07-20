class Solution {
    public int majorityElement(int[] nums) {
        int count = 1, n = nums.length, element = nums[0];
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
}