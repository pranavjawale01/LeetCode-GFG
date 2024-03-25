class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(begin(nums), end(nums));
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                ans.push_back(nums[i-1]);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         map<int, int> mp;
//         vector<int> ans;
//         for (int num : nums) {
//             mp[num]++;
//             if (mp[num] > 1) {
//                 ans.push_back(num);
//             }
//         }
//         return ans;
//     }
// };