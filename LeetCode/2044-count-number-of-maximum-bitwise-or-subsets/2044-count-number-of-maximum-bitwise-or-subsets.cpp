class Solution {
public:
    int OR;
    int count = 0;
    void solve(int i, vector<int> &nums, int ans) {
        if (nums.size() <= i) {
            if (ans == OR) {
                count++;
            }
            return;
        }
        solve(i+1, nums, ans | nums[i]);
        solve(i+1, nums, ans);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        OR = 0;
        for (int x : nums) OR = OR | x;
        solve(0, nums, 0);
        return count;
    }
};