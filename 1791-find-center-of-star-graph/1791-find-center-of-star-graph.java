class Solution {
    public int findCenter(int[][] edges) {
        int n = edges.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int[] edge : edges) {
            mp.put(edge[0], mp.getOrDefault(edge[0], 0) + 1);
            mp.put(edge[1], mp.getOrDefault(edge[1], 0) + 1);
        }
        for (Map.Entry<Integer, Integer> x : mp.entrySet()) {
            if (x.getValue() == n) {
                return x.getKey();
            }
        }
        return -1;
    }
}