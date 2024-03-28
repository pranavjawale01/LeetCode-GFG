class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int i = 0, j = 0, len = 0, n = nums.length;
        while (j < n) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            while (mp.get(nums[j]) > k) {
                mp.put(nums[i], mp.getOrDefault(nums[i], 0) - 1);
                i++;
            }
            len = Math.max(len, j - i + 1);
            j++;
        }
        return len;
    }
}