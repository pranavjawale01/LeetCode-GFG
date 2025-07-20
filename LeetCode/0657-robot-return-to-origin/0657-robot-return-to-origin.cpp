class Solution {
public:
    bool judgeCircle(string moves) {
        int v = 0, h = 0;
        for (char c : moves) {
            if (c == 'U') {
                v += 1;
            } else if (c == 'D') {
                v -= 1;
            } else if (c == 'R') {
                h += 1;
            } else if (c == 'L') {
                h -= 1;
            }
        }
        return v == 0 && h == 0;
    }
};