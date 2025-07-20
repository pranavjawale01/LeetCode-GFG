class Solution {
    public int nonSpecialCount(int l, int r) {
        int threshold = (int) Math.sqrt(r);
        
        int[] prime = new int[threshold + 1];
        Arrays.fill(prime, 1);
        prime[0] = 0;
        prime[1] = 0;
        
        for (int i = 2; i * i <= threshold; i++) {
            if (prime[i] == 1) {
                for (int j = i * i; j <= threshold; j += i) {
                    prime[j] = 0;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i <= threshold; i++) {
            if (prime[i] == 1) {
                int sq = i * i;
                if (sq >= l && sq <= r) {
                    count++;
                }
            }
        }
        
        int totalNumbers = r - l + 1;
        
        return totalNumbers - count;
    }
}