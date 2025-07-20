// 1. Mathematics + Binary Search

class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n  * (n + 1) / 2;
        int left = 1, right = n;
        while (left <= right) {
            int mid_pivot = left + (right - left) / 2;
            if (mid_pivot * mid_pivot == totalSum) {
                return mid_pivot;
            } else if (mid_pivot * mid_pivot > totalSum) {
                right = mid_pivot - 1;
            } else {
                left = mid_pivot + 1;
            }
        }
        return -1;
    }
};
// // 2. Mathematics

// class Solution {
// public:
//     int pivotInteger(int n) {
//         int totalSum = n  * (n + 1) / 2;
//         int i = sqrt(totalSum);
//         if (i * i == totalSum) {
//             return i;
//         }
//         return -1;
//     }
// };

// // 3. Two Pointer

// class Solution {
// public:
//     int pivotInteger(int n) {
//         int lSum = 1, rSum = n;
//         int left = 1, right = n;
//         while (left < right) {
//             if (lSum == rSum) {
//                 left++;
//                 right--;
//                 lSum += left;
//                 rSum += right;
//             } else if (lSum > rSum) {
//                 right--;
//                 rSum += right;
//             } else {
//                 left++;
//                 lSum += left;
//             }
//         }
//         if (lSum == rSum) {
//             return left;
//         }
//         return -1;
//     }
// };

// 4. Brute Force Optimized

// class Solution {
// public:
//     int pivotInteger(int n) {
//         int lSum = 0, rSum = 0;
//         int totalSum = n * (n + 1) / 2;
//         for (int i = 1; i <= n; i++) {
//             lSum = i * (i + 1) / 2;
//             rSum = totalSum - lSum + i;
//             if (lSum == rSum) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// 5.Brute Force

// class Solution {
// public:
//     int pivotInteger(int n) {
//         int lSum = 0, rSum = 0;
//         for (int i = 1; i <= n; i++) {
//             lSum += i;
//             for (int j = i; j <= n; j++) {
//                 rSum += j;
//             }
//             if (lSum == rSum) {
//                 return i;
//             }
//             rSum = 0;
//         }
//         return -1;
//     }
// };