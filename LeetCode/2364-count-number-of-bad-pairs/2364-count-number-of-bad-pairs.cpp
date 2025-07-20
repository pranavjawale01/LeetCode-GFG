class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        long long n = nums.size();
        unordered_map<long long, long long> mp;
        for (int i = 0; i < n; i++) {
            int val = i - nums[i];
            if (mp.find(val) != mp.end()) {
                ans += mp[val];
            }
            mp[val]++;
        }
        return (long long)n * (n - 1) / 2 - ans;
    }
};