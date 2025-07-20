class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int inc = 1, dec = 1;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i+1]) inc++;
            else inc = 1;
            if (nums[i] > nums[i+1]) dec++;
            else dec = 1;
            ans = max(ans, max(inc, dec));
        }
        return ans;
    }
};