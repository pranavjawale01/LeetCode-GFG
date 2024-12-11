class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = 0;
        int maxBeauty = 0;

        while (i < n) {

            while (j < n && nums[j] - nums[i] <= 2 * k) {
                j++;
            }

            maxBeauty = max(maxBeauty, j - i);

            i++;
        }

        return maxBeauty;
    }
};








// class Solution {
// public:
//     int maximumBeauty(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int maxBeauty = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             auto ub = upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k);
//             maxBeauty = max(maxBeauty, int(ub - nums.begin()) - i);
//         }
//         return maxBeauty;
//     }
// };






// // class Solution {
// // public:
// //     int maximumBeauty(vector<int>& nums, int k) {
// //         vector<pair<int, int>> ranges;
// //         for (int x : nums) {
// //             ranges.push_back({x-k, x+k});
// //         }
// //         sort(ranges.begin(), ranges.end());
// //         int maxBeauty = 0;
// //         deque<int> dq;
// //         for (auto &x : ranges) {
// //             while (!dq.empty() && dq.front() < x.first) {
// //                 dq.pop_front();
// //             }
// //             dq.push_back(x.second);
// //             maxBeauty = max(maxBeauty, (int)dq.size());
// //         }
// //         return maxBeauty;
// //     }
// // };