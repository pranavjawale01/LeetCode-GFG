class Solution {
    private int dijikstra(int s, int n, List<List<Integer>> mp) {
        int[] dist = new int[n];
        Arrays.fill(dist, n);
        Queue<Integer> q = new LinkedList<>();
        dist[s] = 0;
        q.add(s);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : mp.get(u)) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.add(v);
                }
            }
        }
        return dist[n - 1];
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] ans = new int[queries.length];
        List<List<Integer>> mp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            mp.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            mp.get(i).add(i + 1);
        }
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            mp.get(query[0]).add(query[1]);
            ans[i] = dijikstra(0, n, mp);
        }
        return ans;
    }
}