class Solution {
    public int maximumLength(String s) {
        int n = s.length();
        int[][] freq = new int[26][n + 1];
        for (int i = 0, len = 1; i < n; i++) {
            char c = s.charAt(i);
            if (i > 0 && s.charAt(i) == s.charAt(i - 1)) {
                len++;
            } else {
                len = 1;
            }
            freq[c - 'a'][len]++;
        }
        int ans = -1;
        for (int ch = 0; ch < 26; ch++) {
            for (int len = n; len > 0; len--) {
                if (len < n) {
                    freq[ch][len] += freq[ch][len + 1];
                }
                if (freq[ch][len] >= 3) {
                    ans = Math.max(ans, len);
                }
            }
        }
        return ans;
    }
}












// class Solution {
//     public int maximumLength(String s) {
//         int n = s.length();
//         Map<String, Integer> mp = new HashMap<>();
//         int maxlen = -1;
//         for (int i = 0; i < n; i++) {
//             int len = 0;
//             char curr = s.charAt(i);
//             for (int j = i; j < n && s.charAt(j) == curr; j++) {
//                 len++;
//                 String key = curr + "," + len;
//                 mp.put(key, mp.getOrDefault(key, 0) + 1);
//             }
//         }
//         for (Map.Entry<String, Integer> entry : mp.entrySet()) {
//             if (entry.getValue() >= 3) {
//                 int len = Integer.parseInt(entry.getKey().split(",")[1]);
//                 maxlen = Math.max(maxlen, len);
//             }
//         }
//         return maxlen == 0 ? -1 : maxlen;
//     }
// }