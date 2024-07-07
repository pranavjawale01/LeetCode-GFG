class Solution {
    public void rev(StringBuilder s, int i, int j) {
        while (i < j) {
            char temp = s.charAt(i);
            s.setCharAt(i, s.charAt(j));
            s.setCharAt(j, temp);
            i++;
            j--;
        }
    }
    
    public String getEncryptedString(String s, int k) {
        int n = s.length();
        k = k % n;
        StringBuilder sb = new StringBuilder(s);
        rev(sb, 0, k - 1);
        rev(sb, k, n - 1);
        rev(sb, 0, n - 1);
        return sb.toString();
    }
}