class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        int n = nums.length;
        int maxEl = 0;
        for (int i = 0; i < n; i++) {
            maxEl = Math.max(maxEl, nums[i]);
        }
        int[] arr = new int[maxEl+1];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                arr[Math.abs(nums[i] - nums[j])]++;
            }
        }
        for (int d = 0; d < maxEl + 1; d++) {
            k -= arr[d];
            if (k <= 0) {
                return d;
            }
        }
        return -1;
    }
}