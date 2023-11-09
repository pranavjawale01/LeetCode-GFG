class Solution {
    public int jump(int[] nums) {
        int lastJump = 0, maxReach = 0, steps = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            maxReach = Math.max(maxReach, i + nums[i]);
            if (i == lastJump) {
                lastJump = maxReach;
                steps++;
            }
        }
        return steps;
    }
}