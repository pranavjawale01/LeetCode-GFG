class Solution {
    public String findValidPair(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        for (char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            int a = s.charAt(i) - '0';
            int b = s.charAt(i + 1) - '0';
            if (a != b && mp.get(s.charAt(i)) == a && mp.get(s.charAt(i + 1)) == b) {
                return s.substring(i, i + 2);
            }
        }        
        return "";
    }
}