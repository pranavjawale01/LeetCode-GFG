class Solution {
    public int[] findRightInterval(int[][] intervals) {
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        int n = intervals.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            mp.put(intervals[i][0], i);
        }
        for (int i = 0; i < n; i++) {
            Integer key = mp.ceilingKey(intervals[i][1]);
            ans[i] = (key == null) ? -1 : mp.get(key);            
        }
        return ans;
    }
}