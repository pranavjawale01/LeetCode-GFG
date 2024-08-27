class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        Map<Integer, List<int[]>> adj = new HashMap<>();
        double[] result = new double[n];
        
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, i});
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[]{u, i});
        }
        
        PriorityQueue<double[]> pq = new PriorityQueue<>(Comparator.comparingDouble(a -> -a[0]));
        result[start_node] = 1.0;
        pq.add(new double[]{1.0, start_node});
        
        while (!pq.isEmpty()) {
            double[] curr = pq.poll();
            double curr_prob = curr[0];
            int curr_node = (int) curr[1];
            
            if (curr_node == end_node) {
                return curr_prob;
            }
            
            for (int[] neighbor : adj.getOrDefault(curr_node, new ArrayList<>())) {
                int next_node = neighbor[0];
                double edge_prob = succProb[neighbor[1]];
                
                if (result[next_node] < curr_prob * edge_prob) {
                    result[next_node] = curr_prob * edge_prob;
                    pq.add(new double[]{result[next_node], next_node});
                }
            }
        }
        
        return 0.0;
    }
}