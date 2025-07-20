class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder ans = new StringBuilder();
        int n = word1.length(), m = word2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            if (i < n) {
                ans.append(word1.charAt(i));
                i++;
            }
            if (j < m) {
                ans.append(word2.charAt(j));
                j++;
            }
        }
        return ans.toString();
    }
}