class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        Map<Integer, List<int[]>> mp = new HashMap<>();
        for (int[] x : times) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            mp.computeIfAbsent(u, key -> new ArrayList<>()).add(new int[]{v, w});
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.offer(new int[]{0, k});
        int[] result = new int[n+1];
        Arrays.fill(result, Integer.MAX_VALUE);
        result[k] = 0;
        while (!pq.isEmpty()) {
            int[] node = pq.poll();
            int dist = node[0];
            int u    = node[1];
            if (mp.containsKey(u)) {
                for (int[] x : mp.get(u)) {
                    int v = x[0];
                    int d = x[1];
                    if (d + dist < result[v]) {
                        result[v] = d + dist;
                        pq.offer(new int[]{d + dist, v});
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (result[i] == Integer.MAX_VALUE) return -1;
            ans = Math.max(ans, result[i]);
        }
        return ans;
    }
}