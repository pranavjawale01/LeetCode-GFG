class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }
        
        int result = 0;
        
        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && last[c] > first[c]) {
                vector<bool> middle(26, false);
                for (int i = first[c] + 1; i < last[c]; i++) {
                    middle[s[i] - 'a'] = true;
                }
                result += count(middle.begin(), middle.end(), true);
            }
        }
        
        return result;
    }
};