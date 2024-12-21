class Solution {
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(i, new ArrayList<>());
        }
        int[] degree = new int[n];
        for (int[] x : edges) {
            mp.get(x[0]).add(x[1]);
            mp.get(x[1]).add(x[0]);
            degree[x[0]]++;
            degree[x[1]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.offer(i);
        }
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = (long)values[i];
        }
        int count = 0;
        while (!q.isEmpty()) {
            int top = q.poll();
            degree[top]--;
            long sum = (arr[top] % k == 0) ? 0 : arr[top];
            if (sum == 0) count++;
            for (Integer x : mp.get(top)) {
                if (degree[x] > 0) {
                    degree[x]--;
                    arr[x] += sum;
                    if (degree[x] == 1) {
                        q.offer(x);
                    }
                }
            }
        }
        return count;
    }
}