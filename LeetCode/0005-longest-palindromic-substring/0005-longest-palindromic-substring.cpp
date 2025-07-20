class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) {
            return "";
        }

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxlen = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxlen = 2;
            }
        }

        for (int length = 3; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxlen = length;
                }
            }
        }

        return s.substr(start, maxlen);
    }
};


// TLE

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int n = s.length();
//         for (int i = 0; i < n / 2; i++) {
//             if (s[i] != s[n - i - 1]) {
//                 return false;
//             }
//         }
//         return true;
//     }
    
//     string longestPalindrome(string s) {
//         int maxLen = INT_MIN;
//         int n = s.length();
//         int start = -1, end = -1;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 if (isPalindrome(s.substr(i, j - i + 1))) {
//                     if (maxLen < j - i + 1) {
//                         maxLen = j - i + 1;
//                         start = i;
//                         end = j;
//                     }
//                 }
//             }
//         }
//         return (start == -1 || end == -1) ? "" : s.substr(start, maxLen);
//     }
// };



// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if(s.length() <= 1) {
//             return s;
//         }
//         int max_len = 1;
//         int n = s.length();
//         int st=0,end=0;
//         for(int i=0; i < n; ++i) {
//             int l=i, r = i;
//             while(l >= 0 && r < n) {
//                 if(s[l] == s[r]) {
//                     l--, r++;
//                 }
//                 else {
//                     break;
//                 }
//             }
//             int len = r - l - 1;
//             if(len > max_len) {
//                 max_len = len;
//                 st = l + 1;
//                 end = r - 1;
//             }
//         }
//         for(int i=0; i < n - 1; ++i) { 
//             int l = i, r = i + 1;
//             while(l >= 0 && r < n) {
//                 if(s[l] == s[r]) {
//                     l--, r++;
//                 }
//                 else {
//                     break;
//                 }
//             }
//             int len = r - l - 1;
//             if(len > max_len) {
//                 max_len = len;
//                 st = l + 1;
//                 end = r - 1;
//             }
//         }
//         return s.substr(st, max_len);
//     }
// };