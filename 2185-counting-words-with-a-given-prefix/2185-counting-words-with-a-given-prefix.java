class Solution {
    public int prefixCount(String[] words, String pref) {
        int n = pref.length();
        int count = 0;
        for (String x : words) {
            if (x.length() >= n && x.substring(0, n).equals(pref)) {
                count++;
            }
        }
        return count;
    }
}