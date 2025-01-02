class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length;
        int[] pref = new int[n];
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));

        for (int i = 0; i < n; i++) {
            if (i > 0) pref[i] = pref[i - 1];
            if (vowels.contains(words[i].charAt(0)) && vowels.contains(words[i].charAt(words[i].length() - 1))) {
                pref[i]++;
            }
        }

        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = pref[r] - (l > 0 ? pref[l - 1] : 0);
        }

        return ans;
    }
}