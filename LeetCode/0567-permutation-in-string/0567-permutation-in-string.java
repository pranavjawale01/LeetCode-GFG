class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];
        int n = s1.length();
        int m = s2.length();
        
        for (int i = 0; i < n; i++) {
            freq1[s1.charAt(i) - 'a']++;
        }
        
        int i = 0, j = 0;
        while (i < m) {
            freq2[s2.charAt(i) - 'a']++;
            if (i >= n) {
                freq2[s2.charAt(j++) - 'a']--;
            }
            if (Arrays.equals(freq1, freq2)) {
                return true;
            }
            i++;
        }
        
        return false;
    }
}