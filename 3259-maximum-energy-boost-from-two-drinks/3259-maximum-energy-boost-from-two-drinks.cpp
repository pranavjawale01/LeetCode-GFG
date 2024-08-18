class Solution {
public:
    using ll = long long;

    long long maxEnergyBoost(vector<int> &A, vector<int> &B) {
        ll a1 = 0, b1 = 0;
        ll a2 = 0, b2 = 0;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            ll curra = A[i] + max(a1, b2);
            ll currb = B[i] + max(b1, a2);

            a2 = a1;
            a1 = curra;

            b2 = b1;
            b1 = currb;
        }
        return max(a1, b1);
    }
};




// class Solution {
// public:
//     int n;
//     long long dp[100000][2];
//     long long solve(int i, int j, vector<int> &a, vector<int> &b) {
//         if (i >= n) {
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         long long ans = (j == 0) ? a[i] : b[i];
//         ans += max(solve(i+1, j, a, b), solve(i+2, 1-j, a, b));
//         return dp[i][j] = ans;
//     }
//     long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
//         n = energyDrinkA.size();
//         memset(dp, -1, sizeof(dp));
//         return max(solve(0, 0, energyDrinkA, energyDrinkB), solve(0, 1, energyDrinkA, energyDrinkB));
//     }
// };