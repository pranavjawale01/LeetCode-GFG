class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int l = 0, orVal = 0;
        if (k == 0) return 1;
        for (int i = 0; i < n; i++) {
            orVal |= nums[i];
            while (orVal >= k && l < n) {
                ans = min(ans, i - l + 1);
                orVal ^= nums[l];
                l++;
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};