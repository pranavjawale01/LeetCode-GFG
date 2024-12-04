class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        for (int i = 0, j = 0; i < m; i++) {
            if ((str1[i] == str2[j]) || (str1[i] - 'a' + 1) % 26 == (str2[j] - 'a')) {
                j++;
            }
            if (j == n) return true;
        }
        return false;
    }
};