class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int maxCount = 0, ans = 0;
        for (int num : nums) {
            mp.put(num , mp.getOrDefault(num, 0) + 1);
            maxCount = Math.max(maxCount, mp.get(num));
        }
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if (entry.getValue() == maxCount) {
                ans += entry.getValue();
            }
        }
        return ans;
    }
}