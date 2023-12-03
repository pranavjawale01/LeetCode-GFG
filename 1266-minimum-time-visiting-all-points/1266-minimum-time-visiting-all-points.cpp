class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int totalTime = 0;
        
        for (int i = 1; i < points.size(); ++i) {
            int xDiff = abs(points[i][0] - points[i - 1][0]);
            int yDiff = abs(points[i][1] - points[i - 1][1]);
            
            int diagonalMoves = (xDiff < yDiff) ? xDiff : yDiff;            
            int remainingMoves = abs(xDiff - yDiff);            
            totalTime += diagonalMoves + remainingMoves;
        }
        
        return totalTime;
    }
};