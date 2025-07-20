class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int left = nums[0], j = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[j]) {
                res += (long long)left * (i - j);
                left = nums[i];
                j = i;
            }
        }
        res += (long long)left * (n - 1 - j);
        return res;
    }
};