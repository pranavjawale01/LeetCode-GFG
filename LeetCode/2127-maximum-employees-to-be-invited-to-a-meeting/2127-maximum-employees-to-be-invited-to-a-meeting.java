class Solution {
    private int bfs(int start, Map<Integer, List<Integer>> graph, boolean[] visited) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{start, 0});
        int maxDist = 0;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currNode = current[0];
            int dist = current[1];

            for (int neighbor : graph.getOrDefault(currNode, new ArrayList<>())) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.offer(new int[]{neighbor, dist + 1});
                    maxDist = Math.max(maxDist, dist + 1);
                }
            }
        }
        return maxDist;
    }

    public int maximumInvitations(int[] favorite) {
        int n = favorite.length;
        Map<Integer, List<Integer>> graph = new HashMap<>();

        for (int i = 0; i < n; i++) {
            graph.computeIfAbsent(favorite[i], k -> new ArrayList<>()).add(i);
        }

        int longestCycleLength = 0;
        int happyCoupleCount = 0;
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                Map<Integer, Integer> seen = new HashMap<>();
                int currNode = i;
                int steps = 0;

                while (!visited[currNode]) {
                    visited[currNode] = true;
                    seen.put(currNode, steps);
                    int nextNode = favorite[currNode];
                    steps++;

                    if (seen.containsKey(nextNode)) {
                        int cycleLength = steps - seen.get(nextNode);
                        longestCycleLength = Math.max(longestCycleLength, cycleLength);

                        if (cycleLength == 2) {
                            boolean[] tempVisited = new boolean[n];
                            tempVisited[currNode] = true;
                            tempVisited[nextNode] = true;
                            happyCoupleCount += 2 + bfs(currNode, graph, tempVisited) + bfs(nextNode, graph, tempVisited);
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }
        return Math.max(happyCoupleCount, longestCycleLength);
    }
}