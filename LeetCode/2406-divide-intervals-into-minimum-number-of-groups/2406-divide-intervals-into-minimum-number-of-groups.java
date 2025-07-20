class Solution {
    public int minGroups(int[][] intervals) {
        Map<Integer, Integer> mp = new TreeMap<>();
        for (int[] x : intervals) {
            int a = x[0], b = x[1];
            b++;
            mp.put(a, mp.getOrDefault(a, 0) + 1);
            mp.put(b, mp.getOrDefault(b, 0) - 1);
        }
        int maxGrp = 0, curGrp = 0;
        for (Map.Entry<Integer, Integer> x : mp.entrySet()) {
            curGrp += x.getValue();
            maxGrp = Math.max(maxGrp, curGrp);
        }
        return maxGrp;
    }
}