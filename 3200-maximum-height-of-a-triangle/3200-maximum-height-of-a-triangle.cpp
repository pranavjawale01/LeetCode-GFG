class Solution {
public:
    int solve(int a, int b) {
        int row = 0;
        int len = 1;
        int height = 0;
        while (a > 0 || b > 0) {
            if (row == 0) {
                if (a >= len) {
                    a -= len;
                } else {
                    break;
                }
            } else {
                if (b >= len) {
                    b -= len;
                } else {
                    break;
                }
            }
            row ^= 1;
            len++;
            height++;
        }
        return height;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red, blue), solve(blue, red));
    }
};