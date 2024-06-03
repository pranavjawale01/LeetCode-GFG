class Solution {
public:
    bool judgeCircle(string moves) {
        int dir = 0;
        for (char c : moves) {
            if (c == 'U') {
                dir += 1;
            } else if (c == 'D') {
                dir -= 1;
            } else if (c == 'R') {
                dir += 2;
            } else if (c == 'L') {
                dir -= 2;
            }
        }
        return dir == 0;
    }
};