class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) {
            return n;
        }
        int t0 = 0, t1 = 1, t2 = 1;
        for (int i = 3; i <= n; i++) {
            int temp = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = temp;
        }
        return t2;
    }
};


// class Solution {
// public:
//     int tribonacci(int n) {
//         vector<int> memo(n + 1, -1);
//         return helper(n, memo);
//     }

//     int helper(int n, vector<int>& memo) {
//         if (n == 0) return 0;
//         if (n == 1 || n == 2) return 1;
//         if (memo[n] != -1) return memo[n];
//         memo[n] = helper(n - 1, memo) + helper(n - 2, memo) + helper(n - 3, memo);
//         return memo[n];
//     }
// };