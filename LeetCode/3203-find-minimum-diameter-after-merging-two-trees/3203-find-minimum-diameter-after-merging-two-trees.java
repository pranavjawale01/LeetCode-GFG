class Solution {
    public Map<Integer, List<Integer>> buildGraph(int[][] edges) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            graph.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }
        return graph;
    }
    
    public int[] findFarthest(int node, int parent, int distance, Map<Integer, List<Integer>> graph, int[] res) {
        if (distance > res[0]) {
            res[0] = distance;
            res[1] = node;
        }
        for (int neighbor : graph.getOrDefault(node, new ArrayList<>())) {
            if (neighbor != parent) {
                findFarthest(neighbor, node, distance + 1, graph, res);
            }
        }
        return res;
    }

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        Map<Integer, List<Integer>> graph1 = buildGraph(edges1);
        Map<Integer, List<Integer>> graph2 = buildGraph(edges2);
        
        int[] res1 = new int[]{Integer.MIN_VALUE, -1};
        findFarthest(0, -1, 0, graph1, res1);
        int[] res2 = new int[]{Integer.MIN_VALUE, -1};
        findFarthest(res1[1], -1, 0, graph1, res2);
        int d1 = res2[0];

        res1 = new int[]{Integer.MIN_VALUE, -1};
        findFarthest(0, -1, 0, graph2, res1);
        res2 = new int[]{Integer.MIN_VALUE, -1};
        findFarthest(res1[1], -1, 0, graph2, res2);
        int d2 = res2[0];

        return Math.max(d1, Math.max(d2, ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1));
    }
}