class Solution {
    public void solve1(int val, int[] bitarr, boolean isAdd) {
        int i = 0;
        while (val > 0) {
            bitarr[i] = bitarr[i] + (isAdd ? 1 : -1) * (val % 2);
            val /= 2;
            i++;
        }
    }

    public boolean solve2(int k, int[] bitarr) {
        int val = 0;
        for (int i = 0; i < 32; i++) {
            if (bitarr[i] >= 1) {
                val |= 1 << i;
            }
        }
        return val >= k;
    }

    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        int i = 0, j = 0;
        int ans = Integer.MAX_VALUE;
        int sumor = 0;
        int[] bitarr = new int[32];

        while (j < n) {
            solve1(nums[j], bitarr, true);
            while (i <= j && solve2(k, bitarr)) {
                ans = Math.min(ans, j - i + 1);
                solve1(nums[i], bitarr, false);
                i++;
            }
            j++;
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}