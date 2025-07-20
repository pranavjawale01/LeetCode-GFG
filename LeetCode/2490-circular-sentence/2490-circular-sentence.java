import java.util.StringTokenizer;

class Solution {
    public boolean isCircularSentence(String sentence) {
        int n = sentence.length();
        if (sentence.charAt(0) != sentence.charAt(n - 1)) {
            return false;
        }
        
        StringTokenizer st = new StringTokenizer(sentence);
        String prev = "", curr = "";
        
        if (st.hasMoreTokens()) {
            prev = st.nextToken();
        }
        
        while (st.hasMoreTokens()) {
            curr = st.nextToken();
            if (curr.charAt(0) != prev.charAt(prev.length() - 1)) {
                return false;
            }
            prev = curr;
        }
        
        return true;
    }
}