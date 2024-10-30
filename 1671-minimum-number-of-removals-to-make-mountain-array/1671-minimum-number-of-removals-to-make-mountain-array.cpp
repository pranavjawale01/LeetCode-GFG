class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), lds(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    lds[i] = max(lds[i], 1 + lds[j]);
                }
            }
        }
        int ans = n;
        for (int i = 1; i < n - 1; i++) {
            ans = min(ans, n - lis[i] - lds[i] + 1);
        }
        return ans;
    }
};