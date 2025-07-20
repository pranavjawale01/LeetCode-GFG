class Solution {
    public int[] sortArray(int[] nums) {
        int minE = Integer.MAX_VALUE;
        int maxE = Integer.MIN_VALUE;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int x : nums) {
            minE = Math.min(minE, x);
            maxE = Math.max(maxE, x);
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        int j = 0;
        for (int i = minE; i <= maxE; i++) {
            while (mp.getOrDefault(i, 0) > 0) {
                nums[j] = i;
                j++;
                mp.put(i, mp.getOrDefault(i, 0) - 1);
            }
        }
        return nums;
    }
}