class Solution {
    public int minSubarray(int[] nums, int p) {
        long totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }
        
        int rem = (int)(totalSum % p);
        if (rem == 0) return 0;
        
        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1);
        
        long prefixSum = 0;
        int ans = nums.length;
        
        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];
            int currMod = (int)(prefixSum % p);
            currMod = (currMod + p) % p;
            
            int target = (currMod - rem + p) % p;
            
            if (mp.containsKey(target)) {
                ans = Math.min(ans, i - mp.get(target));
            }
            
            mp.put(currMod, i);
        }
        
        return ans == nums.length ? -1 : ans;
    }
}