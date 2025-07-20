class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        int i = 0, j = 0;
        string ans = "";
        while (i < n && j < m) {
            ans += word1[i];
            i++;
            ans += word2[j];
            j++;
        }
        while (i < n) {
            ans += word1[i];
            i++;
        }
        while (j < m) {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};