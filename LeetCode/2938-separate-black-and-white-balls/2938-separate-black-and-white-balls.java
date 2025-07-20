class Solution {
    public long minimumSteps(String s) {
        int white = 0;
        long ans = 0;
        int n = s.length();
        
        for (int j = 0; j < n; j++) {
            if (s.charAt(j) == '0') {
                ans += white;
            }
            if (s.charAt(j) == '1') {
                white++;
            }
        }
        
        return ans;
    }
}