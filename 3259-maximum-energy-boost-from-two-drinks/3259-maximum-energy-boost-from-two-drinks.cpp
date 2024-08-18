class Solution {
public:
    int n;
    long long dp[100000][2];
    long long solve(int i, int j, vector<int> &a, vector<int> &b) {
        if (i >= n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        long long ans = (j == 0) ? a[i] : b[i];
        ans += max(solve(i+1, j, a, b), solve(i+2, 1-j, a, b));
        return dp[i][j] = ans;
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        n = energyDrinkA.size();
        memset(dp, -1, sizeof(dp));
        return max(solve(0, 0, energyDrinkA, energyDrinkB), solve(0, 1, energyDrinkA, energyDrinkB));
    }
};