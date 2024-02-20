class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = n;
        int l = 0, r = n-1;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            if (nums[mid] > mid) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int result = n;
//         for (int i = 0; i < n; i++) {
//             result ^= i;
//             result ^= nums[i];
//         }
//         return result;
//     }
// };

// // class Solution {
// // public:
// //     int missingNumber(vector<int>& nums) {
// //         int n = nums.size();
// //         int sum = n*(n+1)/2;
// //         for (int i = 0; i < n; i++) {
// //             sum -= nums[i];
// //         }
// //         return sum;
// //     }
// // };

// // // class Solution {
// // // public:
// // //     int missingNumber(vector<int>& nums) {
// // //         sort(nums.begin(), nums.end());
// // //         if (nums[0] != 0) {
// // //             return 0;
// // //         }
// // //         int n = nums.size();
// // //         for (int i = 0; i < n-1; i++) {
// // //             if (nums[i] + 1 != nums[i+1]) {
// // //                 return i+1;
// // //             }
// // //         }
// // //         return n;
// // //     }
// // // };