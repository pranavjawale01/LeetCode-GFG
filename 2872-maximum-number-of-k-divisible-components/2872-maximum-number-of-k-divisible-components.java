class Solution {
    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int[] degree = new int[n];
        for (int i = 0; i < n; i++) {
            graph.put(i, new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                queue.offer(i);
            }
        }
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = values[i];
        }
        int count = 0;
        while (!queue.isEmpty()) {
            int top = queue.poll();
            degree[top]--;
            long sum = (arr[top] % k == 0) ? 0 : arr[top];
            if (sum == 0) {
                count++;
            }
            for (int neighbor : graph.get(top)) {
                if (degree[neighbor] > 0) {
                    degree[neighbor]--;
                    arr[neighbor] += sum;
                    if (degree[neighbor] == 1) {
                        queue.offer(neighbor);
                    }
                }
            }
        }
        return count == 0 ? 1 : count;
    }
}