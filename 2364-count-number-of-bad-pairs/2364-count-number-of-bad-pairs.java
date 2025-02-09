class Solution {
    public long countBadPairs(int[] nums) {
        long ans = 0;
        int n = nums.length;
        Map<Long, Long> map = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            long val = (long) i - nums[i];
            if (map.containsKey(val)) {
                ans += map.get(val);
            }
            map.put(val, map.getOrDefault(val, 0L) + 1);
        }
        
        return (long) n * (n - 1) / 2 - ans;
    }
}