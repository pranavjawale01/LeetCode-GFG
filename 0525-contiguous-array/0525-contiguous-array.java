class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int result = 0, currSum = 0, n = nums.length;
        mp.put(0, -1);
        for (int i = 0; i < n; i++) {
            currSum += nums[i] == 1 ? 1 : -1;
            if (mp.containsKey(currSum)) {
                result = Math.max(result, i - mp.get(currSum));
            } else {
                mp.put(currSum, i);      
            }
        }
        return result;
    } 
}