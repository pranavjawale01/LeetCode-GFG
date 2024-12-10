class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> freq(26, vector<int>(n + 1, 0));
        for (int i = 0, len = 1; i < n; i++) {
            char c = s[i];
            if (i > 0 && s[i] == s[i - 1]) {
                len++;
            } else {
                len = 1;
            }
            freq[c - 'a'][len]++;
        }
        int ans = 0;
        for (int ch = 0; ch < 26; ch++) {
            for (int len = n; len > 0; len--) {
                if (len < n) {
                    freq[ch][len] += freq[ch][len + 1];
                }
                if (freq[ch][len] >= 3) {
                    ans = max(ans, len);
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};