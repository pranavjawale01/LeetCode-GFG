class Solution {
    public Map<Character, Integer> findCharCount(String str) {
        Map<Character, Integer> charCount = new HashMap<>();
        for (char ch : str.toCharArray()) {
            charCount.put(ch, charCount.getOrDefault(ch, 0) + 1);
        }
        return charCount;
    }
    public int countCharacters(String[] words, String chars) {
        int count = 0;
        Map<Character, Integer> charCount = findCharCount(chars);

        for (String word: words) {
            Map<Character, Integer> wordCount = findCharCount(word);
            boolean check = true;
            for (char ch : word.toCharArray()) {
                if (wordCount.getOrDefault(ch,0) > charCount.getOrDefault(ch,0)) {
                    check = false;
                    break;
                }
            }
            if (check) {
                count += word.length();
            }
        }

        return count;
    }
}