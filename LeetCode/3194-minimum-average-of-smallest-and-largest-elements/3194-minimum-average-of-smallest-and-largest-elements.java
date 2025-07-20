class Solution {
    public double minimumAverage(int[] nums) {
        double minEl = Integer.MAX_VALUE;
        Arrays.sort(nums);
        int i = 0, j = nums.length - 1;
        while (i <= j) {
            double avg = (double) (nums[i] + nums[j]) / 2;
            minEl = Math.min(minEl, avg);
            i++;
            j--;
        }
        return minEl;
    }
}