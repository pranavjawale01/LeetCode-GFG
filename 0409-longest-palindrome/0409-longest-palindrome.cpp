class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int ans = 0, maxOdd = 0;
        for (auto x : mp) {
            if (x.second % 2 == 0) {
                ans += x.second;
            } else {
                maxOdd = max(maxOdd, x.second);
            }
        }
        return ans + maxOdd;
    }
};