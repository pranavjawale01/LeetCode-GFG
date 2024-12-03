class Solution {
    private static final long MOD = 1000000007;

    // Rabin Karp hashValue method
    private long hashValue(String s, long RADIX, int m) {
        long ans = 0, factor = 1;
        for (int i = m - 1; i >= 0; i--) {
            ans = (ans + ((s.charAt(i) - 'a') * factor) % MOD) % MOD;
            factor = (factor * RADIX) % MOD;
        }
        return ans % MOD;
    }

    // Rabin Karp strStr method
    private int strStr(String haystack, String needle) {
        int n = haystack.length(), m = needle.length();
        if (n < m) return -1;

        long RADIX = 26, MAX_WEIGHT = 1;
        for (int i = 1; i <= m; i++) {
            MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
        }

        long hashNeedle = hashValue(needle, RADIX, m), hashHay = 0;

        for (int i = 0; i <= n - m; i++) {
            if (i == 0) {
                hashHay = hashValue(haystack, RADIX, m);
            } else {
                hashHay = ((hashHay * RADIX) % MOD - ((haystack.charAt(i - 1) - 'a') * MAX_WEIGHT) % MOD + (haystack.charAt(i + m - 1) - 'a') + MOD) % MOD;
            }
            if (hashNeedle == hashHay) {
                for (int j = 0; j < m; j++) {
                    if (needle.charAt(j) != haystack.charAt(j + i)) break;
                    if (j == m - 1) return i;
                }
            }
        }
        return -1;
    }

    public int repeatedStringMatch(String a, String b) {
        if (a.equals(b)) return 1;
        int ans = 1;
        StringBuilder src = new StringBuilder(a);
        while (src.length() < b.length()) {
            src.append(a);
            ans++;
        }
        if (src.toString().equals(b)) return ans;
        if (strStr(src.toString(), b) != -1) {
            return ans;
        }
        src.append(a);
        ans++;
        if (strStr(src.toString(), b) != -1) {
            return ans;
        }
        return -1;
    }
}