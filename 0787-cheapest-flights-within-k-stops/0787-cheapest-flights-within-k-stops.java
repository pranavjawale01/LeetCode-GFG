class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] distance = new int[n];
        Arrays.fill(distance, Integer.MAX_VALUE);
        Map<Integer, List<int[]>> adj = new HashMap<>();

        for (int[] flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];
            adj.computeIfAbsent(u, key -> new ArrayList<>()).add(new int[]{v, cost});
        }

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{src, 0});
        distance[src] = 0;
        int level = 0;

        while (!q.isEmpty() && level <= k) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int[] current = q.poll();
                int u = current[0];
                int d = current[1];
                List<int[]> neighbors = adj.getOrDefault(u, Collections.emptyList());
                for (int[] neighbor : neighbors) {
                    int v = neighbor[0];
                    int cost = neighbor[1];
                    if (distance[v] > d + cost) {
                        distance[v] = d + cost;
                        q.offer(new int[]{v,d + cost});
                    }
                }
            }
            level++;
        }
        return distance[dst] == Integer.MAX_VALUE ? -1 : distance[dst];
    }
}