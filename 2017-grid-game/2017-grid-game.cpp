class Solution {
public:
    #define ll long long
    #define all(x) x.begin(), x.end()

    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll firstRowSum = accumulate(all(grid[0]), 0ll);
        ll secondRowSum = 0;
        ll minRob2Sum = LONG_LONG_MAX;

        for (ll i = 0; i < n; i++) {
            firstRowSum -= grid[0][i];
            ll bestOfRobot2 = max(firstRowSum, secondRowSum);
            minRob2Sum = min(minRob2Sum, bestOfRobot2);
            secondRowSum += grid[1][i];
        }

        return minRob2Sum;
    }
};