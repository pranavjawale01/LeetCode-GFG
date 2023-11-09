class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0, steps = 0, lastJump = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);
            if (i == lastJump) {
                lastJump = maxReach;
                steps++;
            }
        }
        return steps;
    }
};