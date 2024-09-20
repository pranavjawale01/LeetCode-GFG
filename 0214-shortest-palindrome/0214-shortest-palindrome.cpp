class Solution {
public:
    void computeLPS(const string& pattern, vector<int>& lps) {
        int M = pattern.size();
        int len = 0;
        lps[0] = 0;
        int i = 1;
        
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;
        
        vector<int> lps(temp.size(), 0);
        computeLPS(temp, lps);
        
        int longestPalindromePrefixLen = lps.back();
        
        string ans = rev.substr(0, s.size() - longestPalindromePrefixLen) + s;
        return ans;
    }
};







// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         string rev = s;
//         reverse(rev.begin(), rev.end());
//         int n = s.length();
//         for (int i = 0; i < n; i++) {
//             if (memcmp(s.c_str(), rev.c_str() + i, n - i) == 0) {
//                 return rev.substr(0, i) + s;
//             }
//         }
//         return rev + s;
//     }
// };







// MLE
// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         string rev = s;
//         reverse(rev.begin(), rev.end());
//         int n = s.length();
//         for (int i = 0; i < n; i++) {
//             if (s.substr(0, n - i) == rev.substr(i)) {
//                 return rev.substr(0, i) + s;
//             }
//         }
//         return rev + s;
//     }
// };