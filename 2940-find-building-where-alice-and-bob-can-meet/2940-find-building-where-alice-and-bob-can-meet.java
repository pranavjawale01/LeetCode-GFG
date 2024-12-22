class Solution {
    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        int n = heights.length;
        int queryCount = queries.length;
        int[] result = new int[queryCount];
        Arrays.fill(result, -1);

        List<List<int[]>> deferredQueries = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            deferredQueries.add(new ArrayList<>());
        }

        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

        for (int queryIndex = 0; queryIndex < queryCount; ++queryIndex) {
            int aliceStart = queries[queryIndex][0];
            int bobStart = queries[queryIndex][1];

            if (aliceStart == bobStart) {
                result[queryIndex] = aliceStart;
            } else if (aliceStart < bobStart && heights[aliceStart] < heights[bobStart]) {
                result[queryIndex] = bobStart;
            } else if (aliceStart > bobStart && heights[aliceStart] > heights[bobStart]) {
                result[queryIndex] = aliceStart;
            } else {
                int maxHeight = Math.max(heights[aliceStart], heights[bobStart]);
                int maxIndex = Math.max(aliceStart, bobStart);
                deferredQueries.get(maxIndex).add(new int[]{maxHeight, queryIndex});
            }
        }

        for (int currentBuilding = 0; currentBuilding < n; ++currentBuilding) {
            while (!minHeap.isEmpty() && minHeap.peek()[0] < heights[currentBuilding]) {
                int queryIndex = minHeap.poll()[1];
                result[queryIndex] = currentBuilding;
            }

            for (int[] query : deferredQueries.get(currentBuilding)) {
                minHeap.offer(query);
            }
        }

        return result;
    }
}