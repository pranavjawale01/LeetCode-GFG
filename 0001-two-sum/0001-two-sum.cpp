class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int req = target - nums[i];
            if (mp.find(req) != mp.end()) {
                return {i, mp[req]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};






// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int, int> mp;
//         for (int i = 0; i < n; i++) {
//             mp[nums[i]] = i;
//         }
//         for (int i = 0; i < n; i++) {
//             int req = target - nums[i];
//             if (mp.find(req) != mp.end() && i != mp[req]) {
//                 return {i, mp[req]};
//             }
//         }
//         return {};
//     }
// };