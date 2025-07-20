class Solution {
    public String reversePrefix(String word, char ch) {
        int n = word.length();
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (word.charAt(i) == ch) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return word;
        }
        StringBuilder str = new StringBuilder(word);
        for (int i = 0; i <= index / 2; i++) {
            char temp = str.charAt(i);
            str.setCharAt(i, str.charAt(index - i));
            str.setCharAt(index - i, temp);
        }
        return str.toString();
    }
}