class Solution {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);
        Arrays.fill(last, -1);

        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }

        int result = 0;

        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && last[c] > first[c]) {
                boolean[] middle = new boolean[26];
                for (int i = first[c] + 1; i < last[c]; i++) {
                    middle[s.charAt(i) - 'a'] = true;
                }
                for (boolean hasChar : middle) {
                    if (hasChar) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
}