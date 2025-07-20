class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long ans = 0;
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        int j = 0;
        long curr = 0;
        for (int i = 0; i < n; i++) {
            curr += nums[i];
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
            while (mp.get(nums[i]) > 1) {
                mp.put(nums[j], mp.getOrDefault(nums[j], 0) - 1);
                curr -= nums[j];
                j++;
            }
            if (i - j + 1 == k) {
                ans = Math.max(ans, curr);
                mp.put(nums[j], mp.getOrDefault(nums[j], 0) - 1);
                curr -= nums[j];
                j++;
            }
        }
        return ans;
    }
}