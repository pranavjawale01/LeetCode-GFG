class Solution {
public:
    void solve1(int val, vector<int> &bitarr, bool isAdd) {
        int i = 0;
        while (val > 0) {
            bitarr[i] = bitarr[i] + (isAdd ? 1 : -1) * val % 2;
            val /= 2;
            i++;
        }
    }
    bool solve2(int k, vector<int> &bitarr) {
        int val = 0;
        for (int i = 0; i < 32; i++) {
            if (bitarr[i]) {
                val |= 1 << i;
            }
        }
        return val >= k;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        int ans = INT_MAX;
        int sumor = 0;
        vector<int> bitarr(32, 0);
        while (j < n) {
            solve1(nums[j], bitarr, true);
            while (i <= j && solve2(k, bitarr)) {
                ans = min(ans, j - i + 1);
                solve1(nums[i], bitarr, false);
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};