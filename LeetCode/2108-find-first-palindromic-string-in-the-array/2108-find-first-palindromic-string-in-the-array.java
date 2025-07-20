class Solution {
    public boolean isPalli(String word) {
        String newWord = new StringBuilder(word).reverse().toString();
        return word.equals(newWord);
    }

    public String firstPalindrome(String[] words) {
        for (String word : words) {
            if (isPalli(word)) {
                return word;
            }
        }
        return "";
    }
}