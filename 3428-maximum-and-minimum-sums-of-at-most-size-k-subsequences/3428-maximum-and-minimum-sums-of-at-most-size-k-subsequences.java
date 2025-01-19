class Solution {
    private static final long MOD = 1000000007;

    private long modpow(long b, long e) {
        long ans = 1;
        while (e > 0) {
            if ((e & 1) == 1) {
                ans = (ans * b) % MOD;
            }
            b = (b * b) % MOD;
            e >>= 1;
        }
        return ans;
    }

    private long counter(long n, long r, long[] fact, long[] invFact) {
        if (r > n || r < 0) return 0;
        return (fact[(int) n] * invFact[(int) r] % MOD) * invFact[(int) (n - r)] % MOD;
    }

    public int minMaxSums(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        long[] fact = new long[n + 1];
        long[] invFact = new long[n + 1];
        fact[0] = invFact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[n] = modpow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                long cnt = counter(n - i - 1, j - 1, fact, invFact);
                ans = (ans + nums[i] * cnt) % MOD;
            }
            for (int j = 1; j <= k; j++) {
                long cnt = counter(i, j - 1, fact, invFact);
                ans = (ans + nums[i] * cnt) % MOD;
            }
        }
        return (int) ans;
    }
}