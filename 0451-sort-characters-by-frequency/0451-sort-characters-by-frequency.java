class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        for (char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        } 
        
        List<Character> charList = new ArrayList<>();
        for (char c : s.toCharArray()) {
            charList.add(c);
        }
        
        Comparator<Character> comparator = (a, b) -> {
            if (mp.get(a).equals(mp.get(b))) {
                return a - b;
            }
            return mp.get(b) - mp.get(a);
        };
        
        Character[] charArray = charList.toArray(new Character[charList.size()]);
        Arrays.sort(charArray, comparator);
        
        StringBuilder sb = new StringBuilder();
        for (char c : charArray) {
            sb.append(c);
        }
        
        return sb.toString();
    }
}