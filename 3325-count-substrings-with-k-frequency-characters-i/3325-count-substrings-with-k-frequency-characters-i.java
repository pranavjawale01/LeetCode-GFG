class Solution {
    public int numberOfSubstrings(String s, int k) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int[] freq = new int[26];
            for (int j = i; j < n; j++) {
                freq[s.charAt(j) - 'a']++;
                if (freq[s.charAt(j) - 'a'] >= k) {
                    count += n - j;
                    break;
                }
            }
        }
        return count;
    }
}