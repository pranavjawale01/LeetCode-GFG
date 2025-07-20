class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int sz = l; sz <= r; sz++) {
            int curr = 0;            
            for (int i = 0; i < sz; i++) curr += nums[i];
            if (curr > 0) ans = min(ans, curr);
            for (int i = sz; i < n; i++) {
                curr += nums[i] - nums[i - sz];                
                if (curr > 0) ans = min(ans, curr);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};