class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            ans = ans ^ nums[i];
        }
        int count = (ans ^ k);
        return __builtin_popcount(count);
    }
};