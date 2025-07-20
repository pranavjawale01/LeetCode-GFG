class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        int[] money = new int[n + 1];
        money[0] = 0;
        money[1] = nums[0];
        
        for (int i = 2; i <= n; i++) {
            int steal = nums[i-1] + money[i-2];
            int skip = money[i-1];
            money[i] = Math.max(steal, skip);
        }
        
        return money[n];
    }
}