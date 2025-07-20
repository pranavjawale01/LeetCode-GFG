class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int x : arr) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        
        int n = arr.length;
        int[] freqCount = new int[n + 1];
        int uniqueTypes = mp.size();
        
        for (int freq : mp.values()) {
            freqCount[freq]++;
        }
        
        for (int freq = 1; freq <= n; freq++) {
            int typesICanDelete = Math.min(k / freq, freqCount[freq]);
            k -= (typesICanDelete * freq);
            uniqueTypes -= typesICanDelete;
            
            if (k <= freq) {
                return uniqueTypes;
            }
        }
        
        return 0;
    }
}