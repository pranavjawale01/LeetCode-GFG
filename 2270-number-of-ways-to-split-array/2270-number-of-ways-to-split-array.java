class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        long[] pref = new long[n];
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            long left = pref[i];
            long right = pref[n-1] - pref[i];
            if (left >= right) ans++;
        }
        return ans;
    }
}