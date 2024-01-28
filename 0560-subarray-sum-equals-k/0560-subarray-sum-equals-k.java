class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int result = 0, cumSum = 0;
        mp.put(0, 1);

        for (int i = 0; i < nums.length; i++) {
            cumSum += nums[i];
            if (mp.containsKey(cumSum - k)) {
                result += mp.get(cumSum - k);
            }
            mp.put(cumSum, mp.getOrDefault(cumSum, 0) + 1);
        }

        return result;
    }
}