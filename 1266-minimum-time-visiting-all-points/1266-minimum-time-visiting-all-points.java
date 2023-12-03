class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int totalTime = 0;

        for (int i = 1; i < points.length; ++i) {
            int xDiff = Math.abs(points[i][0] - points[i - 1][0]);
            int yDiff = Math.abs(points[i][1] - points[i - 1][1]);

            int diagonalMoves = Math.max(xDiff,yDiff);
            totalTime += diagonalMoves;
        }

        return totalTime;
    }
}