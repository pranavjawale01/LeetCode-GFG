class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    t[i][j] = j;
                } else if (j == 0) {
                    t[i][j] = i;
                } else if (word1[i-1] == word2[j-1]) {
                    t[i][j] = t[i-1][j-1];
                } else {
                    t[i][j] = 1 + min({t[i-1][j], t[i][j-1], t[i-1][j-1]});
                }
            }
        }
        return t[m][n];
    }
};



// class Solution {
// public:
//     int memo[501][501];
//     int n, m;
//     int solve(string &s1, string &s2, int i, int j) {
//         if (i == m) {
//             return n - j;
//         } else if (j == n) {
//             return m - i;
//         }
//         if (memo[i][j] != -1) {
//             return memo[i][j];
//         }
//         if (s1[i] == s2[j]) {
//             return memo[i][j] = solve(s1, s2, i+1, j+1);
//         } else {
//             int insertS = 1 + solve(s1, s2, i, j+1);
//             int deleteS = 1 + solve(s1, s2, i+1, j);
//             int replaceS = 1 + solve(s1, s2, i+1, j+1);
//             return memo[i][j] = min({insertS, deleteS, replaceS});
//         }
//         return memo[i][j] = -1;
//     }
//     int minDistance(string word1, string word2) {
//         memset(memo, -1, sizeof(memo));
//         m = word1.length();
//         n = word2.length();
//         return solve(word1, word2, 0, 0);
//     }
// };