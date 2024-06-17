class Solution {
    public boolean judgeSquareSum(int c) {
        long a = 0;
        long b = (long)Math.sqrt(c);
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
}



// class Solution {
//     public boolean judgeSquareSum(int c) {
//         for (long a = 0; a * a <= c; a++) {
//             int x = c - (int)(a * a);
//             int start = 0, end = x;
//             while (start <= end) {
//                 long mid = start + (end - start) / 2;
//                 if (mid * mid == x) {
//                     return true;
//                 } else if (mid * mid < x) {
//                     start = (int) mid + 1;
//                 } else {
//                     end = (int) mid - 1;
//                 }
//             }
//         }
//         return false;
//     }
// }



// class Solution {
//     public boolean judgeSquareSum(int c) {
//         for (long a = 0; a * a <= c; a++) {
//             double b = Math.sqrt(c - a * a);
//             if (b == (int)b) {
//                 return true;
//             }
//         }
//         return false;
//     }
// }