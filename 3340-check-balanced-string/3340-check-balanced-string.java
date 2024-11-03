class Solution {
    public boolean isBalanced(String num) {
        int a = 0, b = 0;
        int n = num.length();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                b += num.charAt(i) - '0';
            } else {
                a += num.charAt(i) - '0';
            }
        }
        return a == b;
    }
}