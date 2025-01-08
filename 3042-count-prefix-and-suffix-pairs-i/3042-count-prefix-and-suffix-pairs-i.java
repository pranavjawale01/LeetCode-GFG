class Solution {
    public boolean isPrefixAndSuffix(String c, String s) {
        int n = c.length();
        String s1 = s.substring(0, n);
        String s2 = s.substring(s.length() - n);
        return s1.equals(c) && s2.equals(c);
    }

    public int countPrefixSuffixPairs(String[] words) {
        int count = 0;
        int n = words.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
}