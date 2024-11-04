class Solution {
    public String compressedString(String word) {
        StringBuilder ans = new StringBuilder();
        int count = 1;
        int n = word.length();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && word.charAt(i) == word.charAt(i + 1) && count < 9) {
                count++;
            } else {
                ans.append(count).append(word.charAt(i));
                count = 1;
            }
        }
        
        return ans.toString();
    }
}