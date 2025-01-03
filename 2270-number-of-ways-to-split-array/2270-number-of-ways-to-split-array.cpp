class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i-1] + nums[i];
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int left = pref[i];
            int right = pref[n-1] - pref[i];
            if (left >= right) ans++;
        }
        return ans;
    }
};