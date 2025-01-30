import java.util.*;

class Solution {
    public int magnificentSets(int n, int[][] edges) {
        // Step 1: Build adjacency list
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0] - 1).add(edge[1] - 1);
            graph.get(edge[1] - 1).add(edge[0] - 1);
        }

        // Step 2: Check if graph is bipartite
        int[] colors = new int[n];
        Arrays.fill(colors, -1);
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!isBipartite(graph, i, colors)) {
                    return -1;
                }
            }
        }

        // Step 3: Find connected components and get max levels
        boolean[] visited = new boolean[n];
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                List<Integer> component = new ArrayList<>();
                dfs(graph, i, visited, component);

                // Step 4: Find max BFS level for this component
                int maxLevels = 0;
                for (int node : component) {
                    maxLevels = Math.max(maxLevels, bfs(graph, node, n));
                }
                result += maxLevels;
            }
        }
        return result;
    }

    // Function to check if the graph is bipartite using DFS
    private boolean isBipartite(List<List<Integer>> graph, int node, int[] colors) {
        Stack<Integer> stack = new Stack<>();
        stack.push(node);
        colors[node] = 0;

        while (!stack.isEmpty()) {
            int curr = stack.pop();
            for (int neighbor : graph.get(curr)) {
                if (colors[neighbor] == colors[curr]) {
                    return false;
                }
                if (colors[neighbor] == -1) {
                    colors[neighbor] = 1 - colors[curr];
                    stack.push(neighbor);
                }
            }
        }
        return true;
    }

    // DFS to find all nodes in a connected component
    private void dfs(List<List<Integer>> graph, int node, boolean[] visited, List<Integer> component) {
        Stack<Integer> stack = new Stack<>();
        stack.push(node);
        visited[node] = true;

        while (!stack.isEmpty()) {
            int curr = stack.pop();
            component.add(curr);
            for (int neighbor : graph.get(curr)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }

    // BFS to find the maximum level from a given start node
    private int bfs(List<List<Integer>> graph, int start, int n) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];
        queue.add(start);
        visited[start] = true;
        int level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            level++;
            for (int i = 0; i < size; i++) {
                int curr = queue.poll();
                for (int neighbor : graph.get(curr)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue.add(neighbor);
                    }
                }
            }
        }
        return level;
    }
}