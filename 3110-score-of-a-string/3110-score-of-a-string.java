class Solution {
    public int scoreOfString(String s) {
        int diff = 0;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            diff += Math.abs((s.charAt(i) - 'a') - (s.charAt(i+1) - 'a'));
        }
        return diff;
    }
}