class Solution {
    public String nearestPalindromic(String n) {
        int len = n.length();
        long prefix = Long.parseLong(n.substring(0, (len + 1) / 2));
        Set<Long> candidates = new TreeSet<>();
        
        for (int i = -1; i <= 1; ++i) {
            String p = Long.toString(prefix + i);
            String pal = p + new StringBuilder(p).reverse().substring(len % 2);
            candidates.add(Long.parseLong(pal));
        }
        
        candidates.add((long) Math.pow(10, len - 1) - 1);
        candidates.add((long) Math.pow(10, len) + 1);
        
        long num = Long.parseLong(n);
        long minDiff = Long.MAX_VALUE;
        long result = 0;
        
        for (long candidate : candidates) {
            if (candidate != num) {
                long diff = Math.abs(candidate - num);
                if (diff < minDiff || (diff == minDiff && candidate < result)) {
                    minDiff = diff;
                    result = candidate;
                }
            }
        }
        
        return Long.toString(result);
    }
}