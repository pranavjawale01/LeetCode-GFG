class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long curr_sum = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            curr_sum += nums[i];
            
            while (mp[nums[i]] > 1) {
                mp[nums[j]]--;
                curr_sum -= nums[j];
                j++;
            }
            
            if (i - j + 1 == k) {
                ans = max(ans, curr_sum);
                mp[nums[j]]--;
                curr_sum -= nums[j];
                j++;
            }
        }
        
        return ans;
    }
};