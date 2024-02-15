public class Solution {
    public long largestPerimeter(int[] nums) {
        int n = nums.length;

        Arrays.sort(nums);

        long perimeter = 0;
        long cumSum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < cumSum) {
                perimeter = nums[i] + cumSum;
            }
            cumSum += nums[i];
        }

        return perimeter == 0 ? -1 : perimeter;
    }
}