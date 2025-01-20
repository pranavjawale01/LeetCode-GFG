class Solution {
    public int[] longestSpecialPath(int[][] edges, int[] nums) {
        int n = nums.length;
        List<int[]>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            graph[edge[0]].add(new int[]{edge[1], edge[2]});
            graph[edge[1]].add(new int[]{edge[0], edge[2]});
        }

        Map<Integer, Integer> lastPositionMap = new HashMap<>();
        int[] prefixSumDistance = new int[n];
        int[] currentPathNode = new int[n];
        int[] result = new int[]{0, 1};

        dfs(graph, -1, 0, nums, lastPositionMap, prefixSumDistance, 0, currentPathNode, 0, result);

        return result;
    }

    private void dfs(List<int[]>[] graph, int parent, int src, int[] nums, Map<Integer, Integer> lastPositionMap, int[] prefixSumDistance, int start, int[] currentPathNode, int end, int[] result) {
        currentPathNode[end] = src;
        Integer oldPosition = lastPositionMap.put(nums[src], end);
        start = Math.max(start, (oldPosition == null ? 0 : oldPosition + 1));

        int tempDist = prefixSumDistance[src] - prefixSumDistance[currentPathNode[start]];
        int count = end - start + 1;

        if (tempDist > result[0]) {
            result[0] = tempDist;
            result[1] = count;
        } else if (tempDist == result[0] && count < result[1]) {
            result[1] = count;
        }

        for (int[] child : graph[src]) {
            if (child[0] != parent) {
                prefixSumDistance[child[0]] = prefixSumDistance[src] + child[1];
                dfs(graph, src, child[0], nums, lastPositionMap, prefixSumDistance, start, currentPathNode, end + 1, result);
            }
        }

        lastPositionMap.put(nums[src], oldPosition);
    }
}