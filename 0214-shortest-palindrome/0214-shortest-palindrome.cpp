class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s.substr(0, n - i) == rev.substr(i)) {
                return rev.substr(0, i) + s;
            }
        }
        return rev + s;
    }
};