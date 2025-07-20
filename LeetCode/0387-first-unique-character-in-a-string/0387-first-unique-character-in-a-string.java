class Solution {
    public int firstUniqChar(String s) {
        Map<Character,Integer> mp = new HashMap<>();
        for (char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (mp.get(s.charAt(i)) == 1) {
                return i;
            }
        }
        return -1;
    }
}