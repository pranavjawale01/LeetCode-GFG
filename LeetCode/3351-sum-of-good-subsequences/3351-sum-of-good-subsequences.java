class Solution {
    public int sumOfGoodSubsequences(int[] nums) {
        long ans = 0;
        int n = nums.length;
        int MOD = 1_000_000_007;
        Map<Integer, Long> sum = new HashMap<>();
        Map<Integer, Long> count = new HashMap<>();

        for (int num : nums) {
            ans = (ans + num) % MOD;
            int find1 = num + 1;
            int find2 = num - 1;

            long cnt1 = count.getOrDefault(find1, 0L);
            long sum1 = sum.getOrDefault(find1, 0L);

            ans = (ans + (cnt1 * num % MOD + sum1) % MOD) % MOD;

            long cnt2 = count.getOrDefault(find2, 0L);
            long sum2 = sum.getOrDefault(find2, 0L);

            ans = (ans + (cnt2 * num % MOD + sum2) % MOD) % MOD;

            count.put(num, (count.getOrDefault(num, 0L) + cnt1 + cnt2 + 1) % MOD);
            long curr = (num * (cnt1 + cnt2 + 1)) % MOD;
            sum.put(num, (sum.getOrDefault(num, 0L) + sum1 + sum2 + curr) % MOD);
        }

        return (int) ans;
    }
}