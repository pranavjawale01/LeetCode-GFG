class Solution {
    public int slidingWindow(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int i = 0, j = 0, count = 0, n = nums.length;
        while (j < n) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            while (mp.size() > k) {
                mp.put(nums[i], mp.getOrDefault(nums[i], 0) - 1);
                if (mp.get(nums[i]) == 0) {
                    mp.remove(nums[i]);
                }
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
    public int subarraysWithKDistinct(int[] nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
}