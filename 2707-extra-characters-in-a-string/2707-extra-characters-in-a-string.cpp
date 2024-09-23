class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i+1];
            for (int j = i; j < n; j++) {
                string curr = s.substr(i, j - i + 1);
                if (st.find(curr) != st.end()) {
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};





// class Solution {
// public:
//     vector<int> dp;
    
//     int solve(int i, string &s, unordered_set<string> &st, int &n) {
//         if (i >= n) {
//             return 0;
//         }
        
//         if (dp[i] != -1) {
//             return dp[i];
//         }

//         int result = 1 + solve(i + 1, s, st, n);

//         for (int j = i; j < n; j++) {
//             string curr = s.substr(i, j - i + 1);
            
//             if (st.find(curr) != st.end()) {
//                 result = min(result, solve(j + 1, s, st, n));
//             }
//         }

//         return dp[i] = result;
//     }

//     int minExtraChar(string s, vector<string>& dictionary) {
//         int n = s.length();
//         dp.resize(n+1, -1);
//         unordered_set<string> st(dictionary.begin(), dictionary.end());
//         return solve(0, s, st, n);
//     }
// };