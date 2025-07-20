class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1, 0);
        
        int result1 = 0;
        int result2 = 0;
        
        t[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result1 = t[n-1];
        
        t.clear();
        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i<=n; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result2 = t[n];
        
        return max(result1, result2);
    }
};







// class Solution {
// public:
//     int memo[101];
//     int solve(int i, int j, vector<int> &nums) {
//         if (i >= j) {
//             return 0;
//         }
//         if (memo[i] != -1) {
//             return memo[i];
//         }
//         int take = nums[i] + solve(i+2, j, nums);
//         int nottake = solve(i+1, j, nums);
//         return memo[i] = max(take, nottake);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) {
//             return nums[0];
//         }
//         if (n == 2) {
//             return max(nums[0], nums[1]);
//         }
//         memset(memo, -1, sizeof(memo));
//         int take0 = solve(0, n-1, nums);
//         memset(memo, -1, sizeof(memo));
//         int take1 = solve(1, n, nums);
//         return max(take0, take1);
//     }
// };