class Solution {
    private int[] parent;
    private int[] rank;

    private int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    private void DSU(int x, int y) {
        int parX = find(x);
        int parY = find(y);
        if (parX != parY) {
            if (rank[parY] > rank[parX]) {
                parent[parX] = parY;
            } else if (rank[parY] < rank[parX]) {
                parent[parY] = parX;
            } else {
                parent[parX] = parY;
                rank[parY]++;
            }
        }
    }

    public long countPairs(int n, int[][] edges) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int[] x : edges) {
            DSU(x[0], x[1]);
        }
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int father = find(i);
            mp.put(father, mp.getOrDefault(father, 0) + 1);
        }
        long result = 0;
        long remaining = n;
        for (Map.Entry<Integer, Integer> x : mp.entrySet()) {
            long size = x.getValue();
            result += (size) * (remaining - size);
            remaining -= size;
        }
        return result;
    }
}