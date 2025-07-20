class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n = nums.size();
        int ans = Integer.MAX_VALUE;

        for (int sz = l; sz <= r; sz++) {
            int curr = 0;

            for (int i = 0; i < sz; i++) {
                curr += nums.get(i);
            }
            if (curr > 0) {
                ans = Math.min(ans, curr);
            }

            for (int i = sz; i < n; i++) {
                curr += nums.get(i) - nums.get(i - sz);
                if (curr > 0) {
                    ans = Math.min(ans, curr);
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}