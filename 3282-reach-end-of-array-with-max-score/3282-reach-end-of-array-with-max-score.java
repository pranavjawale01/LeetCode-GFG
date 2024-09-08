class Solution {
    public long findMaximumScore(List<Integer> nums) {
        int n = nums.size();
        long res = 0;
        int left = nums.get(0);
        int j = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums.get(i) > nums.get(j)) {
                res += (long)left * (i - j);
                left = nums.get(i);
                j = i;
            }
        }
        res += (long) left * (n - 1 - j);
        return res;
    }
}