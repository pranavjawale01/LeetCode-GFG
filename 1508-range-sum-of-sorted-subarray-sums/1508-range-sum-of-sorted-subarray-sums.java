class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        List<Long> arr = new ArrayList<>();
        
        for (int i = 0; i < n; ++i) {
            long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                arr.add(sum);
            }
        }

        Collections.sort(arr);

        final long MOD = 1000000007;
        long ans = 0;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + arr.get(i)) % MOD;
        }

        return (int) ans;
    }
}