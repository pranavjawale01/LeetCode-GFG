class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEl = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxEl) {
                int temp = 0;
                while (i < n && nums[i] == maxEl) {
                    temp++;
                    i++;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};