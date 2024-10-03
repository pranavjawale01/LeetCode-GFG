class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = totalSum % p;
        if (rem == 0)
            return 0;

        unordered_map<int, int> prefixmp;
        prefixmp[0] = -1;

        long long prefixSum = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int currMod = prefixSum % p;
            int target = (currMod - rem + p) % p;

            if (prefixmp.find(target) != prefixmp.end()) {
                ans = min(ans, i - prefixmp[target]);
            }

            prefixmp[currMod] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};