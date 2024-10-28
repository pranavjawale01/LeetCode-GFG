class Solution {
    public int longestSquareStreak(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) set.add(num);
        int ans = 0;
        
        for (int x : nums) {
            int count = 0;
            long current = x;
            while (set.contains((int) current)) {
                count++;
                current *= current;
                if (current > 1e5) break;
            }
            if (count >= 2) ans = Math.max(ans, count);
        }
        
        return ans == 0 ? -1 : ans;
    }
}