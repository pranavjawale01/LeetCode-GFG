class Solution {
    public int secondMinimum(int n, int[][] edges, int time, int change) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            graph.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }

        int[] min1 = new int[n + 1];
        int[] min2 = new int[n + 1];
        Arrays.fill(min1, Integer.MAX_VALUE);
        Arrays.fill(min2, Integer.MAX_VALUE);

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{1, 1});
        min1[1] = 0;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int node = current[0];
            int freq = current[1];

            int timePassed = (freq == 1) ? min1[node] : min2[node];

            if (node == n && min2[n] != Integer.MAX_VALUE) {
                return min2[n];
            }

            int div = timePassed / change;
            if (div % 2 == 1) {
                timePassed = change * (div + 1);
            }

            for (int neighbor : graph.getOrDefault(node, Collections.emptyList())) {
                if (min1[neighbor] == Integer.MAX_VALUE) {
                    min1[neighbor] = timePassed + time;
                    queue.offer(new int[]{neighbor, 1});
                } else if (min2[neighbor] == Integer.MAX_VALUE && min1[neighbor] != timePassed + time) {
                    min2[neighbor] = timePassed + time;
                    queue.offer(new int[]{neighbor, 2});
                }
            }
        }
        return -1;
    }
}










// class Solution {
//     public int secondMinimum(int n, int[][] edges, int time, int change) {
//         Map<Integer, List<Integer>> graph = new HashMap<>();
//         for (int[] edge : edges) {
//             graph.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
//             graph.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
//         }

//         int[] min1 = new int[n + 1];
//         int[] min2 = new int[n + 1];
//         Arrays.fill(min1, Integer.MAX_VALUE);
//         Arrays.fill(min2, Integer.MAX_VALUE);

//         PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
//         pq.offer(new int[]{0, 1});
//         min1[1] = 0;

//         while (!pq.isEmpty()) {
//             int[] current = pq.poll();
//             int timePassed = current[0];
//             int node = current[1];

//             if (node == n && min2[n] != Integer.MAX_VALUE) {
//                 return min2[n];
//             }

//             int div = timePassed / change;
//             if (div % 2 == 1) {
//                 timePassed = change * (div + 1);
//             }

//             for (int neighbor : graph.getOrDefault(node, Collections.emptyList())) {
//                 if (min1[neighbor] > timePassed + time) {
//                     min2[neighbor] = min1[neighbor];
//                     min1[neighbor] = timePassed + time;
//                     pq.offer(new int[]{timePassed + time, neighbor});
//                 } else if (min2[neighbor] > timePassed + time && min1[neighbor] != timePassed + time) {
//                     min2[neighbor] = timePassed + time;
//                     pq.offer(new int[]{timePassed + time, neighbor});
//                 }
//             }
//         }
//         return -1;
//     }
// }