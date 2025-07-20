class Solution {
    public boolean isPossibleToRearrange(String s, String t, int k) {
        int n = s.length();
        if (k == 1) return s.equals(t);

        int chunk = n / k;
        String[] sChunk = new String[k];
        String[] tChunk = new String[k];

        for (int i = 0; i < k; i++) {
            sChunk[i] = s.substring(i * chunk, (i + 1) * chunk);
            tChunk[i] = t.substring(i * chunk, (i + 1) * chunk);
        }

        Arrays.sort(sChunk);
        Arrays.sort(tChunk);

        return Arrays.equals(sChunk, tChunk);
    }
}