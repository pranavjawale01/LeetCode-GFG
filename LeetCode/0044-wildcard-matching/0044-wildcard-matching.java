public class Solution {
    public boolean isMatch(String s, String p) {
        int sIndex = 0, pIndex = 0;
        int starIndex = -1, sTempIndex = -1;

        while (sIndex < s.length()) {
            if (pIndex < p.length() && (s.charAt(sIndex) == p.charAt(pIndex) || p.charAt(pIndex) == '?')) {
                sIndex++;
                pIndex++;
            } else if (pIndex < p.length() && p.charAt(pIndex) == '*') {
                starIndex = pIndex;
                sTempIndex = sIndex;
                pIndex++;
            } else if (starIndex != -1) {
                pIndex = starIndex + 1;
                sTempIndex++;
                sIndex = sTempIndex;
            } else {
                return false;
            }
        }

        while (pIndex < p.length() && p.charAt(pIndex) == '*') {
            pIndex++;
        }

        return pIndex == p.length();
    }
}