class Solution {
    public int countPrefixes(String[] words, String s) {
        int count = 0;
        for (String x : words) {
            if (x.length() <= s.length() && s.substring(0, x.length()).equals(x)) {
                count++;
            }
        }
        return count;
    }
}