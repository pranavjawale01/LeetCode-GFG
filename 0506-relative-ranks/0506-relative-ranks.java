class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        
        String[] result = new String[n];
        
        HashMap<Integer, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            mp.put(score[i], i);
        }
        
        Arrays.sort(score);
        
        for (int i = n - 1; i >= 0; i--) {
            int ath = mp.get(score[i]);
            if (i == n - 1) {
                result[ath] = "Gold Medal";
            } else if (i == n - 2) {
                result[ath] = "Silver Medal";
            } else if (i == n - 3) {
                result[ath] = "Bronze Medal";
            } else {
                result[ath] = String.valueOf(n - i);
            }
        }
        
        return result;
    }
}