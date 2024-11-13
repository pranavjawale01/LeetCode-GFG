class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long count = 0;
        int n = nums.length;

        for (int i = 0; i < n - 1; i++) {
            int lowBound = findFirst(nums, i + 1, n, lower - nums[i]);
            int upBound = findFirst(nums, i + 1, n, upper - nums[i] + 1);
            count += (upBound - lowBound);
        }

        return count;
    }

    private int findFirst(int[] nums, int start, int end, int target) {
        int left = start, right = end;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}