class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] freq = new int[26];
        for (String word : words2) {
            int[] temp = new int[26];
            for (char c : word.toCharArray()) temp[c - 'a']++;
            for (int i = 0; i < 26; i++) freq[i] = Math.max(freq[i], temp[i]);
        }
        List<String> result = new ArrayList<>();
        for (String word : words1) {
            int[] temp = new int[26];
            for (char c : word.toCharArray()) temp[c - 'a']++;
            boolean isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > temp[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) result.add(word);
        }
        return result;
    }
}