class Solution {

    private long[][][] dp; 

    private int solve(int[] nums, int i, int k, int op1, int op2) {
        if (i >= nums.length) return 0;

        if (dp[i][op1][op2] != -1) return (int) dp[i][op1][op2];

        int ans = nums[i] + solve(nums, i + 1, k, op1, op2);

        if (op1 > 0) {
            ans = Math.min(ans, (nums[i] + 1) / 2 + solve(nums, i + 1, k, op1 - 1, op2));
        }

        if (op2 > 0 && nums[i] >= k) {
            ans = Math.min(ans, nums[i] - k + solve(nums, i + 1, k, op1, op2 - 1));
        }

        if (op1 > 0 && op2 > 0) {
            int div = (nums[i] + 1) / 2;
            if (div >= k) {
                ans = Math.min(ans, div - k + solve(nums, i + 1, k, op1 - 1, op2 - 1));
            }
        }

        if (op1 > 0 && op2 > 0 && nums[i] >= k) {
            int sub = nums[i] - k;
            ans = Math.min(ans, (sub + 1) / 2 + solve(nums, i + 1, k, op1 - 1, op2 - 1));
        }

        dp[i][op1][op2] = ans;

        return ans;
    }

    public int minArraySum(int[] nums, int k, int op1, int op2) {
        dp = new long[nums.length + 1][op1 + 1][op2 + 1];
        for (long[][] arr2D : dp) {
            for (long[] arr1D : arr2D) {
                Arrays.fill(arr1D, -1);
            }
        }

        return solve(nums, 0, k, op1, op2);
    }
}