class Solution {
    private void computeLPS(String pattern, int[] lps) {
        int M = pattern.length();
        int len = 0;
        lps[0] = 0;
        int i = 1;

        while (i < M) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    public String shortestPalindrome(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        String temp = s + "#" + rev;

        int[] lps = new int[temp.length()];
        computeLPS(temp, lps);

        int longestPalindromePrefixLen = lps[lps.length - 1];

        String ans = rev.substring(0, s.length() - longestPalindromePrefixLen) + s;
        return ans;
    }
}





// class Solution {
//     public String shortestPalindrome(String s) {
//         String rev = new StringBuilder(s).reverse().toString();
//         int n = s.length();
//         for (int i = 0; i < n; i++) {
//             if (s.substring(0, n - i).equals(rev.substring(i))) {
//                 return rev.substring(0, i) + s;
//             }
//         }
//         return rev + s;
//     }
// }