class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n+1, 0);
        for (int i = 0; i < n; i++) {
            vec[min(n, nums[i])]++;
        }
        int cum_sum = 0;
        for (int i = n ; i >= 0; i--) {
            cum_sum += vec[i];
            if (i == cum_sum) {
                return i;
            }
        }
        return -1;
    }
};




// class Solution {
// public:
//     int specialArray(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int l = 0, r = n;
//         while (l <= r) {
//             int mid_x = l + (r - l) / 2;
//             int idx = lower_bound(nums.begin(), nums.end(), mid_x) - nums.begin();
//             int count = n - idx;
//             if (count == mid_x) {
//                 return mid_x;
//             } else if (count > mid_x) {
//                 l = mid_x + 1;
//             } else {
//                 r = mid_x - 1;
//             }
//         }
//         return -1;
//     }
// };




// class Solution {
// public:
//     int specialArray(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         for (int x = 0; x <= n; x++) {
//             //pointer to first elemnet >= x
//             int idx = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
//             int count = n - idx;
//             if (count == x) {
//                 return x;
//             }
//         }
//         return -1;
//     }
// };