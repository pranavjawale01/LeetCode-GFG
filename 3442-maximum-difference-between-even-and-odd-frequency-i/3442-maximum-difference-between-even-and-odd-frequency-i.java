class Solution {
    public int maxDifference(String s) {
        int evenMin = Integer.MAX_VALUE;
        int oddMax = 0;
        int[] freq = new int[26];
        
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] % 2 == 0) {
                evenMin = Math.min(evenMin, freq[i]);
            } else {
                oddMax = Math.max(oddMax, freq[i]);
            }
        }
        
        return oddMax - evenMin;
    }
}