// 3.Two Pointer

class Solution {
    public int pivotInteger(int n) {
        int lSum = 1, rSum = n;
        int left = 1, right = n;
        while (left < right) {
            if (lSum == rSum) {
                left++;
                right--;
                lSum += left;
                rSum += right;
            } else if (lSum < rSum) {
                left++;
                lSum += left;
            } else {
                right--;
                rSum += right;
            }
        }
        if (rSum == lSum) {
            return left;
        }
        return -1;
    }
}

// 4. Optimized Brute Force

// class Solution {
//     public int pivotInteger(int n) {
//         int lSum = 0, rSum = 0;
//         int totalSum = n * (n + 1) / 2;
//         for (int i = 1; i <= n; i++) {
//             lSum = i * (i + 1) / 2;
//             rSum = totalSum - lSum + i;
//             if (rSum == lSum) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// }

// 5.Brute Force

// class Solution {
//     public int pivotInteger(int n) {
//         int lSum = 0, rSum = 0;
//         for (int i = 1; i <= n; i++) {
//             lSum += i;
//             for (int j = i; j <= n; j++) {
//                 rSum += j;
//             }
//             if (rSum == lSum) {
//                 return i;
//             }
//             rSum = 0;
//         }
//         return -1;
//     }
// }