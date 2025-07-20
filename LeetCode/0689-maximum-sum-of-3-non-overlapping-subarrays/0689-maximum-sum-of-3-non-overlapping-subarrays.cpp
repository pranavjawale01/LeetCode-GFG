class Solution {
public:
    int dp[20001][4];

    int helper(vector<int> &sums, int k, int i, int rem) {
        if (rem == 0) return 0;
        if (i >= sums.size()) return INT_MIN;
        if (dp[i][rem] != -1) return dp[i][rem];
        int take = sums[i] + helper(sums, k, i + k, rem - 1);
        int nottake = helper(sums, k, i + 1, rem);
        return dp[i][rem] = max(take, nottake);
    }

    void solve(vector<int> &sums, int k, int i, int rem, vector<int> &idx) {
        if (rem == 0) return;
        if (i >= sums.size()) return;
        int take = sums[i] + helper(sums, k, i + k, rem - 1);
        int nottake = helper(sums, k, i + 1, rem);
        if (take >= nottake) {
            idx.push_back(i);
            solve(sums, k, i + k, rem - 1, idx);
        } else {
            solve(sums, k, i + 1, rem, idx);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size() - k + 1;
        vector<int> sums;
        int sum = 0;
        int i = 0, j = 0;
        while (j < nums.size()) {
            sum += nums[j];
            if (j - i + 1 == k) {
                sums.push_back(sum);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        vector<int> idx;
        solve(sums, k, 0, 3, idx);
        return idx;
    }
};