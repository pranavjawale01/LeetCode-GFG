class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        for (int node = 0; node < n; node++) {
            if (color[node] != 0) {
                continue;
            }
            Queue<Integer> q = new ArrayDeque<>();
            q.add(node);
            color[node] = 1;
            while (!q.isEmpty()) {
                int curr = q.poll();
                for (int ne : graph[curr]) {
                    if (color[ne] == 0) {
                        color[ne] = -color[curr];
                        q.add(ne);
                    } else if (color[ne] != -color[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}




/*
class Solution {
    public boolean dfs(int[][] graph, int[] color, int node, int col) {
        if (color[node] != 0) {
            return (color[node] == col);
        }
        color[node] = col;
        for (int ne : graph[node]) {
            if (!dfs(graph, color, ne, -col)) {
                return false;
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && !dfs(graph, color, i, 1)) {
                return false;
            }
        }
        return true;
    }
}
*/