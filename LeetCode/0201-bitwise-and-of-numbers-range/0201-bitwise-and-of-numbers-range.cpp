class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right = right & (right - 1);
        }
        return right;
    }
};

// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         int shiftCount = 0;
//         while (left != right) {
//             left = (left >> 1);
//             right = (right >> 1);
//             shiftCount++;
//         }
//         return (left << shiftCount);
//     }
// };