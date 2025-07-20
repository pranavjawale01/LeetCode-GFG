class Solution {
    public int solve(int val) {
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < 32; i++) {
            int num = val & ~(1 << i);
            if (num < 0) {
                continue;
            }
            if ((num | (num + 1)) == val) {
                ans = Math.min(ans, num);
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = solve(nums.get(i));
        }
        return ans;
    }
}