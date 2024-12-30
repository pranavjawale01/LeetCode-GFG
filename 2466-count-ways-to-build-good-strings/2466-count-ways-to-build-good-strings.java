class Solution {
    private int ans, l, h, z, o;
    private final int MOD = 1000000007;
    private int[] dp;

    private int solve(int L) {
        if (L > h) return 0;
        if (dp[L] != -1) return dp[L];
        boolean addOne = false;
        if (l <= L && L <= h) addOne = true;
        int takeZero = solve(L + z);
        int takeOne = solve(L + o);
        dp[L] = (int)(((addOne ? 1 : 0) + (long)takeZero + (long)takeOne) % MOD);
        return dp[L];
    }

    public int countGoodStrings(int low, int high, int zero, int one) {
        l = low;
        h = high;
        z = zero;
        o = one;
        dp = new int[h + 1];
        Arrays.fill(dp, -1);
        return solve(0);
    }
}