class Solution {
    public char findKthBit(int n, int k) {
        String s = "0";
        
        for (int i = 2; i <= n; i++) {
            StringBuilder inverted = new StringBuilder(s);
            for (int j = 0; j < inverted.length(); j++) {
                inverted.setCharAt(j, inverted.charAt(j) == '0' ? '1' : '0');
            }
            inverted.reverse();
            s = s + "1" + inverted.toString();
        }
        
        return s.charAt(k - 1);
    }
}