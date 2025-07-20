class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character , Integer> sMap = new HashMap<Character , Integer>();
        Map<Character , Integer> tMap = new HashMap<Character , Integer>();
        for (char c: s.toCharArray()) {
            sMap.put(c, sMap.getOrDefault(c,0) + 1);
        }
        for (char c: t.toCharArray()) {
            tMap.put(c, tMap.getOrDefault(c,0) + 1);
        }
        return sMap.equals(tMap);
    }
}