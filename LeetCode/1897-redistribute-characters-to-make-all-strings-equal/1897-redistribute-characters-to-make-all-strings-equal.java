class Solution {
    public boolean makeEqual(String[] words) {
        Map<Character, Integer> charCount = new HashMap<>();

        for (String word : words) {
            for (char c : word.toCharArray()) {
                charCount.put(c, charCount.getOrDefault(c, 0) + 1);
            }
        }
        
        int numWords = words.length;
        for (int count : charCount.values()) {
            if (count % numWords != 0) {
                return false;
            }
        }

        return true;
    }
}