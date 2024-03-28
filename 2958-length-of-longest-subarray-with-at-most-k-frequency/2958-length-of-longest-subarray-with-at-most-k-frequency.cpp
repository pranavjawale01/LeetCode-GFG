class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, len = 0, n = nums.size();
        while (j < n) {
            mp[nums[j]]++;
            while (i < j && mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }    
            len = max(len , j - i + 1);        
            j++;
        }
        return len;
    }
};