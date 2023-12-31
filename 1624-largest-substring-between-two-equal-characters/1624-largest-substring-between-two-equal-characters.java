class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int n = s.length();
        int maxLen = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    maxLen = Math.max(maxLen, j - i - 1);
                }
            }
        }
        return maxLen;
    }
}