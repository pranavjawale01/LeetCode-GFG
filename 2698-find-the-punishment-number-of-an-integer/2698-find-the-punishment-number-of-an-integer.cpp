class Solution {
public:
    bool check(int num, int curr, int target) {
        if (num == 0) {
            return curr == target;
        }
        return check(num/10, curr + num % 10, target) || check(num/100, curr + num % 100, target) || check(num/1000, curr + num % 1000, target) || check(num / 10000, curr + num % 10000, target);
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            if (check(sq, 0, i)) {
                ans += sq;
            }
        }
        return ans;
    }
};







// class Solution {
// public:
//     bool solve(int i, int currSum, string s, int num, vector<vector<int>> &dp) {
//         if (i == s.size()) {
//             return currSum == num;
//         }
//         if (currSum > num) return false;
//         if (dp[i][currSum] != -1) {
//             return dp[i][currSum];
//         }
//         bool flag = false;
//         for (int j = i; j < s.size(); j++) {
//             string currStr = s.substr(i, j-i+1);
//             int added = stoi(currStr);
//             flag |= solve(j+1, currSum + added, s, num, dp);
//             if (flag) return true;
//         }
//         return dp[i][currSum] = flag;
//     }
//     int punishmentNumber(int n) {
//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             int sq = i * i;
//             string s = to_string(sq);
//             vector<vector<int>> dp(s.size(), vector<int>(i+1, -1));
//             if (solve(0, 0, s, i, dp)) {
//                 ans += sq;
//             }
//         }
//         return ans;
//     }
// };