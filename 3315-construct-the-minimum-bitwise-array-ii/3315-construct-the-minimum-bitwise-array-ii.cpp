class Solution {
public:
    // int pranavjawale01(int low, int high, int val) {
    //     int best = -1;
    //     while (low <= high) {
    //         int mid = low + (high - low) / 2;
    //         if ((mid | (mid + 1)) == val) {
    //             best = mid;
    //             high = mid - 1;
    //         } else if ((mid | (mid + 1)) > val) {
    //             high = mid - 1;
    //         } else {
    //             low = mid + 1;
    //         }
    //     }
    //     return best;
    // }
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