class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                ans.push_back(abs(nums[i]));
            } else {
                nums[index] *= (-1);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         vector<int> ans;
//         sort(begin(nums), end(nums));
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] == nums[i-1]) {
//                 ans.push_back(nums[i-1]);
//             }
//         }
//         return ans;
//     }
// };

// // class Solution {
// // public:
// //     vector<int> findDuplicates(vector<int>& nums) {
// //         map<int, int> mp;
// //         vector<int> ans;
// //         for (int num : nums) {
// //             mp[num]++;
// //             if (mp[num] > 1) {
// //                 ans.push_back(num);
// //             }
// //         }
// //         return ans;
// //     }
// // };