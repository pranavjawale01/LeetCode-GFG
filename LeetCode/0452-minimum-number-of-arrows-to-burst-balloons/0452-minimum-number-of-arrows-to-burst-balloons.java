class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points.length == 0) return 0;
        
        Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));
        
        int count = 1;
        int prevEnd = points[0][1];
        
        for (int i = 1; i < points.length; i++) {
            if (points[i][0] > prevEnd) {
                count++;
                prevEnd = points[i][1];
            } else {
                prevEnd = Math.min(prevEnd, points[i][1]);
            }
        }
        
        return count;
    }
}