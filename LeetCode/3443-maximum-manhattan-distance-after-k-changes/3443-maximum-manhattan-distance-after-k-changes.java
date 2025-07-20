class Solution {
    public int maxDistance(String s, int k) {
        int north = 0, south = 0, east = 0, west = 0;
        int ans = 0;
        
        for (char c : s.toCharArray()) {
            if (c == 'N') north++;
            if (c == 'S') south++;
            if (c == 'E') east++;
            if (c == 'W') west++;
            
            int maxVertical = Math.max(north, south);
            int minVertical = Math.min(north, south);
            int maxHorizontal = Math.max(west, east);
            int minHorizontal = Math.min(west, east);
            int kChanges = Math.min(k, minVertical + minHorizontal);
            
            ans = Math.max(ans, maxVertical + maxHorizontal - minVertical - minHorizontal + 2 * kChanges);
        }
        
        return ans;
    }
}