class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length - 1 , max_reach = 0;
        
        for (int i = 0; i <= n; i++) {
            if (i > max_reach) {
                return false;
            }
            
            max_reach = Math.max(max_reach, i + nums[i]);
            
            if (max_reach >= n) {
                return true;
            }
        }
        return false;
    }
}