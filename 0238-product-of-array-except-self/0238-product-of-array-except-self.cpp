class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i-1];
        }
        int right = 1;
        for (int i = n-1; i >= 0; i--) {
            left[i] = left[i] * right;
            right *= nums[i];
        }
        return left;
    }
};

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> left(n, 1);
//         vector<int> right(n, 1);
//         for (int i = 1; i < n; i++) {
//             left[i] = left[i-1] * nums[i-1];
//             right[n-i-1] = right[n-i] * nums[n-i];
//         }
//         for (int i = 0; i < n; i++) {
//             nums[i] = left[i] * right[i];
//         }
//         return nums;
//     }
// };

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         int zeroCount = 0;
//         int productWithoutZero = 1;
//         for (int &num : nums) {
//             if (num == 0) {
//                 zeroCount++;
//             } else {
//                 productWithoutZero *= num;
//             }
//         }
//         vector<int> result(n, 0);
//         if (zeroCount == 2) {
//             return result;
//         }
//         for (int i = 0; i < n; i++) {
//             int num = nums[i];
//             if (num != 0) {
//                 if (zeroCount > 0) {
//                     result[i] = 0;
//                 } else {
//                     result[i] = productWithoutZero / nums[i];
//                 }
//             } else {
//                 if (zeroCount > 1) {
//                     result[i] = 0;
//                 } else {
//                     result[i] = productWithoutZero;
//                 }
//             }
//         }
//         return result;
//     }
// };

// Brute Force
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp(n, 0);
//         for (int i = 0; i < n; i++) {
//             int tem = 1;
//             for (int j = 0; j < n; j++) {
//                 if (i == j) {
//                     continue;
//                 }
//                 tem *= nums[j];
//             }
//             temp[i] = tem;
//         }
//         return temp;
//     }
// };