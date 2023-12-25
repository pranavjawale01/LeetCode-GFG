class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        
        int x = 0, y = 0;
        
        for (char direction : path) {
            if (direction == 'N') {
                y++;
            } else if (direction == 'S') {
                y--;
            } else if (direction == 'E') {
                x++;
            } else if (direction == 'W') {
                x--;
            }
            if (visited.count({x, y}) > 0) {
                return true;
            }
            visited.insert({x, y});
        }
        return false;
    }
};