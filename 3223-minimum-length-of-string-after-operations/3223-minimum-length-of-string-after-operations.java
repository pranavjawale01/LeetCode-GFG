class Solution {
    public int minimumLength(String s) {
        int[] count = new int[26];
        int remove = 0;
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
            if (count[c - 'a'] == 3) {
                count[c - 'a'] -= 2;
                remove += 2;
            }
        }
        return s.length() - remove;
    }
}