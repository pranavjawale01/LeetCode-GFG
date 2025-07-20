class Solution {
    int[][] dp = new int[20001][4];

    private int helper(int[] sums, int k, int i, int rem) {
        if (rem == 0) return 0;
        if (i >= sums.length) return Integer.MIN_VALUE;
        if (dp[i][rem] != -1) return dp[i][rem];
        int take = sums[i] + helper(sums, k, i + k, rem - 1);
        int notTake = helper(sums, k, i + 1, rem);
        return dp[i][rem] = Math.max(take, notTake);
    }

    private void solve(int[] sums, int k, int i, int rem, List<Integer> idx) {
        if (rem == 0) return;
        if (i >= sums.length) return;
        int take = sums[i] + helper(sums, k, i + k, rem - 1);
        int notTake = helper(sums, k, i + 1, rem);
        if (take >= notTake) {
            idx.add(i);
            solve(sums, k, i + k, rem - 1, idx);
        } else {
            solve(sums, k, i + 1, rem, idx);
        }
    }

    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        int n = nums.length - k + 1;
        int[] sums = new int[n];
        int sum = 0, i = 0, j = 0;
        
        while (j < nums.length) {
            sum += nums[j];
            if (j - i + 1 == k) {
                sums[i] = sum;
                sum -= nums[i];
                i++;
            }
            j++;
        }

        List<Integer> idx = new ArrayList<>();
        solve(sums, k, 0, 3, idx);

        int[] result = new int[idx.size()];
        for (int a = 0; a < idx.size(); a++) {
            result[a] = idx.get(a);
        }
        return result;
    }
}