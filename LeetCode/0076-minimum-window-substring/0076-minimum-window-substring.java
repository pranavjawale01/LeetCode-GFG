import java.util.HashMap;
import java.util.Map;

class Solution {
    public String minWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0 || s.length() < t.length()) {
            return "";
        }

        int len1 = s.length(), len2 = t.length();
        Map<Character, Integer> tMap = new HashMap<>();

        for (char c : t.toCharArray()) {
            tMap.put(c, tMap.getOrDefault(c, 0) + 1);
        }

        int left = 0, right = 0, count = len2, len = Integer.MAX_VALUE;
        int minLeft = 0;

        while (right < len1) {
            if (tMap.containsKey(s.charAt(right)) && tMap.get(s.charAt(right)) > 0) {
                count--;
            }
            tMap.put(s.charAt(right), tMap.getOrDefault(s.charAt(right), 0) - 1);
            right++;

            while (count == 0) {
                if (right - left < len) {
                    len = right - left;
                    minLeft = left;
                }

                tMap.put(s.charAt(left), tMap.get(s.charAt(left)) + 1);
                if (tMap.get(s.charAt(left)) > 0) {
                    count++;
                }
                left++;
            }
        }

        if (len == Integer.MAX_VALUE) {
            return "";
        }

        return s.substring(minLeft, minLeft + len);
    }
}