class Solution {
    public int minSteps(String s, String t) {
        Map<Character, Integer> mp = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i), 0) - 1);
            mp.put(t.charAt(i), mp.getOrDefault(t.charAt(i), 0) + 1);
        }
        int count = 0;
        for (int i = 0; i < t.length(); i++) {
            if (mp.get(t.charAt(i)) > 0) {
                count += mp.get(t.charAt(i));
                mp.put(t.charAt(i), 0);
            }
        }
        return count;
    }
}