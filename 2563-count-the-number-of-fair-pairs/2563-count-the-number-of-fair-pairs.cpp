class Solution {
public:
    long long countInRange(int i, int lower, int upper, vector<int> &nums) {
        int n = nums.size();
        
        int left = i + 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[i] + nums[mid] < lower) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int lowBound = left;
        
        left = i + 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[i] + nums[mid] <= upper) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int upBound = left;
        
        return upBound - lowBound;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            ans += countInRange(i, lower, upper, nums);
        }
        
        return ans;
    }
};