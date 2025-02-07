class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        Map<Integer, Integer> colorCount = new HashMap<>();
        Map<Integer, Integer> prevColor = new HashMap<>();
        int n = queries.length;
        int[] res = new int[n];

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            if (prevColor.containsKey(ball)) {
                int prev = prevColor.get(ball);
                colorCount.put(prev, colorCount.get(prev) - 1);
                if (colorCount.get(prev) == 0) {
                    colorCount.remove(prev);
                }
            }

            prevColor.put(ball, color);
            colorCount.put(color, colorCount.getOrDefault(color, 0) + 1);
            res[i] = colorCount.size();
        }

        return res;
    }
}