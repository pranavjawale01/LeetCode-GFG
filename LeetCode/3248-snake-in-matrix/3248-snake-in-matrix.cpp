class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int count = 0;
        for (auto x : commands) {
            if (x == "UP") {
                count -= n;
            }
            if (x == "DOWN") {
                count += n;
            }
            if (x == "RIGHT") {
                count++;
            }
            if (x == "LEFT") {
                count--;
            }
        }
        return count;
    }
};