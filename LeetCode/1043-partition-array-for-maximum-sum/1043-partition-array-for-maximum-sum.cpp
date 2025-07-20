class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> t(n+1, 0);
        
        for (int i = 1; i <= n; i++) {
            int currMax = -1;
            
            for (int j = 1; j <= k && i - j >= 0; j++) {
                currMax = max(currMax, arr[i - j]);
                t[i] = max(t[i], t[i - j] + currMax * j);
            }
        }

        return t[n];
    }
};

// class Solution {
// public:
//     int n;
//     int mem[501];
//     int solve(int i, vector<int>& arr, int k) {
//         if (i >= n) {
//             return 0;
//         }
//         if (mem[i] != -1) {
//             return mem[i];
//         }
//         int result = 0;
//         int curr_max = -1;

//         for (int j = i; j < n && j - i + 1 <= k; j++) {
//             curr_max = max(curr_max, arr[j]);
//             result = max(result, (curr_max * (j - i + 1)) + solve(j+1, arr, k));
//         }
//         return mem[i] = result;
//     }
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         n = arr.size();
//         memset(mem, -1, sizeof(mem));
//         return solve(0, arr, k);
//     }
// };