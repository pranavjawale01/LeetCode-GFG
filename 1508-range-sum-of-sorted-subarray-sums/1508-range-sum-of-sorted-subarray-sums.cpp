class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> arr;

        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                arr.push_back(sum);
            }
        }

        sort(arr.begin(), arr.end());

        const long long mod = 1e9 + 7;
        long long ans = 0;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + arr[i]) % mod;
        }

        return static_cast<int>(ans);
    }
};