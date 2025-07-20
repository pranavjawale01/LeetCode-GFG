class Solution {
public:
    int solve(int red, int blue) {
        int height = 0;
        int row = 1;
        
        while (true) {
            if (row % 2 == 1) {
                if (red >= row) {
                    red -= row;
                    height++;
                } else {
                    break;
                }
            } else {
                if (blue >= row) {
                    blue -= row;
                    height++;
                } else {
                    break;
                }
            }
            row++;
        }
        
        return height;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red, blue), solve(blue, red));
    }
};



// class Solution {
// public:
//     int solve(int a, int b) {
//         int row = 0;
//         int len = 1;
//         int height = 0;
//         while (a > 0 || b > 0) {
//             if (row == 0) {
//                 if (a >= len) {
//                     a -= len;
//                 } else {
//                     break;
//                 }
//             } else {
//                 if (b >= len) {
//                     b -= len;
//                 } else {
//                     break;
//                 }
//             }
//             row ^= 1;
//             len++;
//             height++;
//         }
//         return height;
//     }
//     int maxHeightOfTriangle(int red, int blue) {
//         return max(solve(red, blue), solve(blue, red));
//     }
// };