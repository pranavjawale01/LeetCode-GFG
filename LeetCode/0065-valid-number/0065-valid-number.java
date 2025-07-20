public class Solution {
    public boolean isNumber(String s) {
        boolean result = false, dFlag = false, eFlag = false;
        int i = 0;

        if (i < s.length() && (s.charAt(i) == '-' || s.charAt(i) == '+')) {
            i++;
        }

        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            result = true;
            i++;
        }

        if (i < s.length() && s.charAt(i) == '.') {
            i++;
            dFlag = true;
        }

        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            result = true;
            i++;
        }

        if (i < s.length() && (s.charAt(i) == 'e' || s.charAt(i) == 'E') && result && !eFlag) {
            i++;
            eFlag = true;
            result = false;
            if (i < s.length() && (s.charAt(i) == '-' || s.charAt(i) == '+')) {
                i++;
            }
        }

        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            result = true;
            i++;
        }

        while (i < s.length() && Character.isWhitespace(s.charAt(i))) {
            i++;
        }

        return result && (i == s.length());
    }
}