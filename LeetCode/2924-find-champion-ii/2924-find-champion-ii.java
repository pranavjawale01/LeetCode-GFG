class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] indegree = new int[n];
        for (int[] x : edges) {
            indegree[x[1]]++;
        }
        int ans = -1;
        int freq = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                ans = i;
                freq++;
                if (freq > 1) return -1;
            }
        }
        return ans;
    }
}