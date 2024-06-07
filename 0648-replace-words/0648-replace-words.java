class Solution {
    public String findWord(String word, Set<String> st) {
        for (int i = 1; i <= word.length(); i++) {
            if (st.contains(word.substring(0, i))) {
                return word.substring(0, i);
            }
        }
        return word;
    }
    
    public String replaceWords(List<String> dictionary, String sentence) {
        Set<String> st = new HashSet<>(dictionary);
        StringBuilder result = new StringBuilder();
        String[] words = sentence.split(" ");
        for (String word : words) {
            result.append(findWord(word, st)).append(" ");
        }
        return result.toString().trim();
    }
}