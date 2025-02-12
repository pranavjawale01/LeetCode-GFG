class Solution {
public:
    int sumOfDigit(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = sumOfDigit(nums[i]);
            if (mp.find(sum) != mp.end()) {
                ans = max(ans, nums[i] + nums[mp[sum]]);
            }
            mp[sum] = i;
        }
        return ans == 0 ? -1 : ans;
    }
};