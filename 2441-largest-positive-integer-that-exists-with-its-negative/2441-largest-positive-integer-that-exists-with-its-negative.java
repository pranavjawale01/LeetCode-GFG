class Solution {
    public int findMaxK(int[] nums) {
        Arrays.sort(nums);
        int low = 0, high = nums.length - 1;
        while (low <= high) {
            if ((nums[low]*(-1)) == nums[high]) {
                return nums[high];
            } else if ((nums[low]*(-1)) < nums[high]) {
                high--;
            } else {
                low++;
            }
        }
        return -1;
    }
}