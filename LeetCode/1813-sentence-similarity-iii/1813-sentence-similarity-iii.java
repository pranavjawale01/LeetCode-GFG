class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        List<String> words1 = splitWords(sentence1);
        List<String> words2 = splitWords(sentence2);
        
        if (words1.size() < words2.size()) {
            List<String> temp = words1;
            words1 = words2;
            words2 = temp;
        }
        
        int start = 0, end = 0;
        int n1 = words1.size(), n2 = words2.size();
        
        while (start < n2 && words1.get(start).equals(words2.get(start))) {
            start++;
        }
        
        while (end < n2 && words1.get(n1 - end - 1).equals(words2.get(n2 - end - 1))) {
            end++;
        }
        
        return start + end >= n2;
    }

    private List<String> splitWords(String sentence) {
        List<String> words = new ArrayList<>();
        StringBuilder word = new StringBuilder();
        
        for (char c : sentence.toCharArray()) {
            if (c == ' ') {
                if (word.length() > 0) {
                    words.add(word.toString());
                    word.setLength(0);
                }
            } else {
                word.append(c);
            }
        }
        
        if (word.length() > 0) {
            words.add(word.toString());
        }
        
        return words;
    }
}