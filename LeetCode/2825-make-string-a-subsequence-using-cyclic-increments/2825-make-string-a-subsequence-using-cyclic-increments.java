class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int m = str1.length(), n = str2.length();
        for (int i = 0, j = 0; i < m; i++) {
            if ((str1.charAt(i) == str2.charAt(j)) || (str1.charAt(i) - 'a' + 1) % 26 == (str2.charAt(j) - 'a')) {
                j++;
            }
            if (j == n) return true;
        }
        return false;
    }
}