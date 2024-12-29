class Solution {
    public String answerString(String word, int numFriends) {
        String ans = "";
        char maxc = word.charAt(0);
        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i) > maxc) {
                maxc = word.charAt(i);
            }
        }
        
        int n = word.length();
        if (numFriends == 1) return word;
        
        for (int i = 0; i < n; i++) {
            if (word.charAt(i) == maxc) {
                int len = Math.min(n - i, n - numFriends + 1);
                if (len <= 0) continue;
                String temp = word.substring(i, i + len);
                if (temp.compareTo(ans) > 0) {
                    ans = temp;
                }
            }
        }
        
        return ans;
    }
}