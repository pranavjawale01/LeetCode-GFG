class Solution {
    public long maximumImportance(int n, int[][] roads) {
        int[] degree = new int[n];
        for (int[] road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        Arrays.sort(degree);
        long val = 1;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (degree[i] * val);
            val++;
        }
        return sum;
    }
}