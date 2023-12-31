class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int maxLen = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n && j != i; j++) {
                if (s[i] == s[j]) {
                    maxLen = max(maxLen, abs(i - j - 1));
                }
            }
        }
        return maxLen;
    }
};