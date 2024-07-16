class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        StringBuilder sb = new StringBuilder();
        
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                sb.append(c);
            }
        }
        
        String filtered = sb.toString();
        
        int i = 0, j = filtered.length() - 1;
        while (i < j) {
            if (filtered.charAt(i) != filtered.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
}