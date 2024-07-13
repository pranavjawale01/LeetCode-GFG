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
        int par_x = find(x);
        int par_y = find(y);
        if (par_x != par_y) {
            if (rank[par_x] > rank[par_y]) {
                parent[par_y] = par_x;
            } else if (rank[par_x] < rank[par_y]) {
                parent[par_x] = par_y;
            } else {
                parent[par_x] = par_y;
                rank[par_y]++;
            }
        }
    }

    public int makeConnected(int n, int[][] connections) {
        int edges = connections.length;
        if (edges < n - 1) {
            return -1;
        }
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int count = n;
        for (int[] x : connections) {
            if (find(x[0]) != find(x[1])) {
                DSU(x[0], x[1]);
                count--;
            }
        }
        return count - 1;
    }
}