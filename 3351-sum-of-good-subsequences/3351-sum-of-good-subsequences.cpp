class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int MOD = 1e9 + 7;
        unordered_map<int, long long> sum, count;
        for (int i = 0; i < n; i++) {
            ans = (ans + nums[i]) % MOD;
            int find1 = nums[i] + 1;
            int find2 = nums[i] - 1;

            long long cnt1 = count[find1];
            long long sum1 = sum[find1];

            ans = (ans + (cnt1 * nums[i] % MOD + sum1) % MOD) % MOD;

            long long cnt2 = count[find2];
            long long sum2 = sum[find2];

            ans = (ans + (cnt2 * nums[i] % MOD + sum2) % MOD) % MOD;

            count[nums[i]] = (count[nums[i]] + cnt1 + cnt2 + 1) % MOD;
            long long curr = ((nums[i]) * (cnt1 + cnt2 + 1)) % MOD;
            sum[nums[i]] = (sum[nums[i]] + sum1 + sum2 + curr) % MOD;
        }
        return ans;
    }
};