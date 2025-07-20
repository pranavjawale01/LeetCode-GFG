class Solution {
    public List<String> commonChars(String[] words) {
        int n = words.length;
        int[] count = new int[26];
        Arrays.fill(count, Integer.MAX_VALUE);

        for (int i = 0; i < n; i++) {
            int[] temp = new int[26];
            for (char c : words[i].toCharArray()) {
                temp[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                count[j] = Math.min(count[j], temp[j]);
            }
        }

        List<String> result = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            while (count[i]-- > 0) {
                result.add(String.valueOf((char)(i + 'a')));
            }
        }

        return result;
    }
}