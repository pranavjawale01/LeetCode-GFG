class Solution {
public:
    int pranavjawale01(int val) {
        int ans = INT_MAX;
        for (int i = 0; i < 32; i++) {
            int num = val & ~(1 << i);
            if (num < 0) {
                continue;
            }
            if ((num | (num + 1)) == val) {
                ans = min(ans, num);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            ans[i] = pranavjawale01(nums[i]);
        }
        return ans;
    }
};