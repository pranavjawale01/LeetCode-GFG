class Solution {
    public int longestSubsequence(int[] arr, int diff) {
        int n = arr.length;
        Map<Integer, Integer> dp = new HashMap<>();
        int maxlen = 1;
        
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            if (dp.containsKey(num - diff)) {
                dp.put(num, dp.get(num - diff) + 1);
            } else {
                dp.put(num, 1);
            }
            maxlen = Math.max(maxlen, dp.get(num));
        }
        
        return maxlen;
    }
}