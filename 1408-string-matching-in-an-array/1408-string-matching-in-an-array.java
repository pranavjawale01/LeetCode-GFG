class Solution {
    public int[] computeLPS(String pattern) {
        int m = pattern.length();
        int[] lps = new int[m];
        int len = 0, i = 1;
        
        while (i < m) {
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
        return lps;
    }
    
    public boolean kmpSearch(String text, String pattern) {
        int n = text.length(), m = pattern.length();
        int[] lps = computeLPS(pattern);
        int i = 0, j = 0;
        
        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
            }
            if (j == m) {
                return true;
            } else if (i < n && text.charAt(i) != pattern.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    
    public List<String> stringMatching(String[] words) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                if (i != j && kmpSearch(words[j], words[i])) {
                    ans.add(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
}







// class Solution {
//     public List<String> stringMatching(String[] words) {
//         List<String> ans = new ArrayList<>();
//         for (String x : words) {
//             for (String y : words) {
//                 if (x.equals(y)) continue;
//                 if (y.contains(x)) {
//                     ans.add(x);
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// }