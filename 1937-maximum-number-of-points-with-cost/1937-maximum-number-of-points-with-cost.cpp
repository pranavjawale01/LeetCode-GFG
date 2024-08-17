class Solution {
public:
    vector<vector<long long>> dp;
    int row, col;
    
    long long solve(vector<vector<int>>& points, int i, int prev) {
        if (i >= row) {
            return 0;
        }
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        
        long long maxEl = LLONG_MIN;
        for (int k = 0; k < col; k++) {
            long long score = points[i][k] + solve(points, i + 1, k);
            if (prev != -1) {
                score -= abs(prev - k);
            }
            maxEl = max(maxEl, score);
        }
        
        return dp[i][prev + 1] = maxEl;
    }
    
    long long maxPoints(vector<vector<int>>& points) {
        row = points.size();
        col = points[0].size();
        dp = vector<vector<long long>>(row, vector<long long>(col + 1, -1));
        
        return solve(points, 0, -1);
    }
};