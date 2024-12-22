class Solution {
    public boolean checkValidCuts(int n, int[][] rectangles) {
        List<int[]> vertical = new ArrayList<>();
        List<int[]> horizontal = new ArrayList<>();
        for (int[] rect : rectangles) {
            vertical.add(new int[]{rect[1], rect[3]});
            horizontal.add(new int[]{rect[0], rect[2]});
        }
        List<int[]> arr = solve(vertical);
        List<int[]> brr = solve(horizontal);
        return arr.size() >= 3 || brr.size() >= 3;
    }

    private List<int[]> solve(List<int[]> intervals) {
        if (intervals.size() <= 1) return intervals;
        intervals.sort((a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> merged = new ArrayList<>();
        merged.add(intervals.get(0));
        for (int i = 1; i < intervals.size(); i++) {
            int[] last = merged.get(merged.size() - 1);
            int[] curr = intervals.get(i);
            if (curr[0] < last[1]) {
                last[1] = Math.max(last[1], curr[1]);
            } else {
                merged.add(curr);
            }
        }
        return merged;
    }
}