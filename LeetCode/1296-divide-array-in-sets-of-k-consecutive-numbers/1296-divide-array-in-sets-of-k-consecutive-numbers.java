class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        int n = nums.length;
        if (n % k != 0) {
            return false;
        }
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        for (int x : nums) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        while (!mp.isEmpty()) {
            int curr = mp.firstKey();
            for (int i = 0; i < k; i++) {
                if (mp.getOrDefault(curr + i, 0) == 0) {
                    return false;
                }
                mp.put(curr + i, mp.get(curr + i) - 1);
                if (mp.get(curr + i) == 0) {
                    mp.remove(curr + i);
                }
            }
        }
        return true;
    }
}