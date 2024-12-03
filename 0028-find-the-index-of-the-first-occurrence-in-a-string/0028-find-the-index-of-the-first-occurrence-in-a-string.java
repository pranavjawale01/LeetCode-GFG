class Solution {
    // KMP Algorithm to find substring
    public int strStr(String haystack, String needle) {
        int n = haystack.length(), m = needle.length();
        if (m == 0) return 0;
        if (n < m) return -1;

        int[] lps = new int[m];
        int len = 0, i = 1;
        
        while (i < m) {
            if (needle.charAt(i) == needle.charAt(len)) {
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

        int j = 0;
        for (i = 0; i < n; i++) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                j++;
                if (j == m) {
                    return i - m + 1;
                }
            } else if (j != 0) {
                j = lps[j - 1];
                i--;
            }
        }
        return -1;
    }
}











// class Solution {
//     private static final long MOD = 1000000007;

//     private long hashValue(String s, long RADIX, int m) {
//         long ans = 0, factor = 1;
//         for (int i = m - 1; i >= 0; i--) {
//             ans = (ans + ((s.charAt(i) - 'a') * factor) % MOD) % MOD;
//             factor = (factor * RADIX) % MOD;
//         }
//         return ans % MOD;
//     }

//     public int strStr(String haystack, String needle) {
//         int n = haystack.length(), m = needle.length();
//         if (n < m) return -1;

//         long RADIX = 26, MAX_WEIGHT = 1;
//         for (int i = 1; i <= m; i++) {
//             MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
//         }

//         long hashNeedle = hashValue(needle, RADIX, m);
//         long hashHay = 0;

//         for (int i = 0; i <= n - m; i++) {
//             if (i == 0) {
//                 hashHay = hashValue(haystack, RADIX, m);
//             } else {
//                 hashHay = ((hashHay * RADIX) % MOD - ((haystack.charAt(i - 1) - 'a') * MAX_WEIGHT) % MOD + (haystack.charAt(i + m - 1) - 'a') + MOD) % MOD;
//             }
//             if (hashNeedle == hashHay) {
//                 for (int j = 0; j < m; j++) {
//                     if (needle.charAt(j) != haystack.charAt(j + i)) break;
//                     if (j == m - 1) return i;
//                 }
//             }
//         }
//         return -1;
//     }
// }