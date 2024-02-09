class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] dp = new int[n];
        int[] index = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(index, -1);
        int lastIndex = 0, maxL = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        index[i] = j;
                    }
                    if (dp[i] > maxL) {
                        maxL = dp[i];
                        lastIndex = i;
                    }
                }
            } 
        }
        List<Integer> result = new ArrayList<>();
        while (lastIndex >= 0) {
            result.add(nums[lastIndex]);
            lastIndex = index[lastIndex];
        }
        return result;
    }
}