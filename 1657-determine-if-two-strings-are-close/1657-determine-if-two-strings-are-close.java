class Solution {
    public boolean closeStrings(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        if (m != n) {
            return false;
        }
        int[] v1 = new int[26];
        int[] v2 = new int[26];
        
        for (int i = 0; i < m; i++) {
            char w1 = word1.charAt(i);
            char w2 = word2.charAt(i);
            
            v1[w1 - 'a']++;
            v2[w2 - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (v1[i] != 0 && v2[i] != 0) {
                continue;
            }
            if (v1[i] == 0 && v2[i] == 0) {
                continue;
            } else {
                return false;
            }
        }
        
        Arrays.sort(v1);
        Arrays.sort(v2);
        
        return Arrays.equals(v1, v2);
    }
}