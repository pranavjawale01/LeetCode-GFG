class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0, b = sqrt(c);
        while (a <= b) {
            long k = a * a + b * b;
            if (k < c) {
                a++;
            } else if (k > c) {
                b--;
            } else {
                return true;
            }
        }
        return false;
    }
};



// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         for (long i = 0; i * i <= c; i++) {
//             int x = c - (int)(i * i);
//             int start = 0, end = x;
//             while (start <= end) {
//                 long mid = start + (end - start) / 2;
//                 if (mid * mid == x) {
//                     return true;
//                 } else if (mid * mid > x) {
//                     end = mid - 1;
//                 } else {
//                     start = mid + 1;
//                 }
//             }
//         }
//         return false;
//     }
// };



// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         for (long i = 0; i * i <= c; i++) {
//             double b = sqrt(c - i * i);
//             if (b == (int)b) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };



// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         for (int i = 0; i * i <= c; i++) {
//             for (int j = 0; j * j <= c; j++) {
//                 if (i * i + j * j == c) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };