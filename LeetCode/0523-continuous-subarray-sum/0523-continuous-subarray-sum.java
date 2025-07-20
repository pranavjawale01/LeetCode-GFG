class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;
        int sum = 0;
        mp.put(0, -1);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remainder = sum % k;
            if (mp.containsKey(remainder)) {
                if (i - mp.get(remainder) >= 2) {
                    return true;
                }
            } else {
                mp.put(remainder, i);
            }
        }
        return false;
    }
}