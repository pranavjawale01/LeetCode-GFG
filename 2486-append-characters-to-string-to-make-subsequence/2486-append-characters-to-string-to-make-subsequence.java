class Solution {
    public int appendCharacters(String s, String t) {
        int i = 0, j = 0;
        int sn = s.length(), tn = t.length();
        while (i < sn && j < tn) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return tn - j;
    }
}