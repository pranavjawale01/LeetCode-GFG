class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int productWithoutZero = 1;
        for (int &num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                productWithoutZero *= num;
            }
        }
        vector<int> result(n, 0);
        if (zeroCount == 2) {
            return result;
        }
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num != 0) {
                if (zeroCount > 0) {
                    result[i] = 0;
                } else {
                    result[i] = productWithoutZero / nums[i];
                }
            } else {
                if (zeroCount > 1) {
                    result[i] = 0;
                } else {
                    result[i] = productWithoutZero;
                }
            }
        }
        return result;
    }
};

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