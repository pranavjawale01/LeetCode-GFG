class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        Map<Integer, Long> mp = new HashMap<>();
        for (int x : nums1) mp.put(x, mp.getOrDefault(x, 0L) + n);
        for (int x : nums2) mp.put(x, mp.getOrDefault(x, 0L) + m);
        int ans = 0;
        for (Map.Entry<Integer, Long> x : mp.entrySet()) {
            if (x.getValue() % 2 != 0) ans ^= x.getKey();
        }
        return ans;
    }
}