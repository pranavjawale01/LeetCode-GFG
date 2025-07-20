class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int count = 0;
        int currSum = 0;
        mp.put(0, 1);
        for (int num : nums) {
            currSum += num;
            if (mp.containsKey(currSum - goal)) {
                count += mp.get(currSum - goal);
            }
            mp.put(currSum, mp.getOrDefault(currSum, 0) + 1);
        }
        return count;
    }
}