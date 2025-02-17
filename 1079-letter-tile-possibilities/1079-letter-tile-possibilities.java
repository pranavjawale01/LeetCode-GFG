class Solution {
    private int ans = 0;

    public int numTilePossibilities(String tiles) {
        int[] count = new int[26];
        for (char c : tiles.toCharArray()) {
            count[c - 'A']++;
        }
        solve(count);
        return ans - 1;
    }

    private void solve(int[] count) {
        ans++;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) continue;
            count[i]--;
            solve(count);
            count[i]++;
        }
    }
}