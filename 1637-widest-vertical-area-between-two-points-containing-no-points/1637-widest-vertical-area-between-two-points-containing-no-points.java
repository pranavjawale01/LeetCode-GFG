class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));
        int wide = 0;
        for (int i = 0; i < points.length - 1; i++) {
            if (points[i+1][0] - points[i][0] > wide) {
                wide = points[i+1][0] - points[i][0];
            }
        }
        return wide;
    }
}