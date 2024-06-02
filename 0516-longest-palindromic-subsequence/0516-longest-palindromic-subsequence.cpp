class Solution {
public:
    int solve(string &s, int start, int end) {
        if (start == end) {
            return 1;
        }
        if (start > end) {
            return 0;
        }
        if (s[start] == s[end]) {
            return 2 + solve(s, start+1, end-1);
        }
        return max(solve(s, start+1, end), solve(s, start, end-1));
    }
    int longestPalindromeSubseq(string s) {
        return solve(s, 0, s.size()-1);
    }
};