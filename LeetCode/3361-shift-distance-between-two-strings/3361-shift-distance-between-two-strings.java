class Solution {
    public long shiftDistance(String s, String t, int[] nextCost, int[] previousCost) {
        long n = s.length();
        long ans = 0;
        for (long i = 0; i < n; i++) {
            long start = s.charAt((int) i) - 'a', end = t.charAt((int) i) - 'a';
            long fs = (end - start + 26) % 26;
            long front = 0;
            for (long j = 0; j < fs; j++) {
                long x = (start + j) % 26;
                front += nextCost[(int) x];
            }
            long bs = (start - end + 26) % 26;
            long back = 0;
            for (long j = 0; j < bs; j++) {
                long x = (start - j + 26) % 26;
                back += previousCost[(int) x];
            }
            ans += Math.min(front, back);
        }
        return ans;
    }
}