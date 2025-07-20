class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0;
        int one = 0;
        for (int x : nums) {
            if (x == 1) {
                one++;
            } else {
                ans = Math.max(ans, one);
                one = 0;
            }
        }
        ans = Math.max(ans, one);
        return ans;
    }
}