class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int i = 0, j = 0, count = 0, mul = 1, n = nums.size();
        while (j < n) {
            mul *= nums[j];
            while (mul >= k) {
                mul /= nums[i];
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
};

// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int n = nums.size(), count = 0;
//         for (int i = 0; i < n; i++) {
//             int mul = 1;
//             for (int j = i; j < n; j++) {
//                 if (mul * nums[j] >= k) {
//                     break;
//                 }
//                 mul *= nums[j];
//                 count++;
//             }
//         }
//         return count;
//     }
// };