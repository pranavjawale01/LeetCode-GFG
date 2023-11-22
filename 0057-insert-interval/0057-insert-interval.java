class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> result = new ArrayList<>();

        int[][] updatedIntervals = Arrays.copyOf(intervals, intervals.length + 1);
        updatedIntervals[intervals.length] = newInterval;

        if (updatedIntervals == null || updatedIntervals.length == 0) {
            return result.toArray(new int[0][]);
        }

        Arrays.sort(updatedIntervals, Comparator.comparingInt(a -> a[0]));

        result.add(updatedIntervals[0]);

        for (int i = 1; i < updatedIntervals.length; i++) {
            if (result.get(result.size() - 1)[1] >= updatedIntervals[i][0]) {
                result.get(result.size() - 1)[1] = Math.max(result.get(result.size() - 1)[1], updatedIntervals[i][1]);
            } else {
                result.add(updatedIntervals[i]);
            }
        }

        return result.toArray(new int[0][]);
    }
}