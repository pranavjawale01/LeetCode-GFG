class Solution {
public:
    int memo[50001];
    int n;
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n-1;
        
        int result = n+1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    
    int solve(vector<vector<int>>& array, int i) {
        if(i >= n)
            return 0;
        
        if(memo[i] != -1)
            return memo[i];
        
        int next  = getNextIndex(array, i+1, array[i][1]);
        
        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i+1);
        
        return memo[i] = max(taken, notTaken);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        
        memset(memo, -1, sizeof(memo));
        
        vector<vector<int>> array(n, vector<int>(3, 0)); //{s, e, p}
        
        for(int i = 0; i<n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        
        auto comp = [&](auto& vec1, auto& vec2) {
              return vec1[0] <= vec2[0];
        };

        sort(begin(array), end(array), comp);
        
        return solve(array, 0);
    }
};


// class Solution {
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         int n = startTime.size();
//         int maxEndTime = *max_element(endTime.begin(), endTime.end());
//         vector<vector<int>> dp(n+1 , vector<int>(maxEndTime+1 , 0));
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= maxEndTime; j++) {
//                 dp[i][j] = dp[i - 1][j];
//                 if (endTime[i - 1] <= j) {
//                     dp[i][j] = max(dp[i][j], profit[i - 1] + dp[i - 1][j - endTime[i - 1]]);
//                 }
//             }
//         }
//         int totalProfit = 0;
//         int i = n, j = maxEndTime;
//         while (i > 0 && j > 0) {
//             if (dp[i][j] != dp[i-1][j]) {
//                 totalProfit += profit[i - 1];
//                 j = startTime[i - 1];
//             }
//             i--;
//         }
//         return totalProfit;
//     }
// };