class Solution {
    public int minimumPushes(String word) {
        HashMap<Character, Integer> mp = new HashMap<>();
        for (char c : word.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }
        int size = mp.size();
        if (size <= 8) {
            return word.length();
        }
        if (size > 8 && size < 17) {
            return 8 + (size - 8) * 2;
        }
        if (size > 16 && size < 25) {
            return 8 + 16 + (size - 16) * 3;
        }
        return 8 + 16 + 24 + (size - 24) * 4;
    }
}