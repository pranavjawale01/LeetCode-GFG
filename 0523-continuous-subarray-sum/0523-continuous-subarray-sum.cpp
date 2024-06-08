class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remainder = sum % k;
            if (mp.find(remainder) != mp.end()) {
                if (i - mp[remainder] >= 2) {
                    return true;
                }
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};




// Brute Force TLE
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             int sum = nums[i];
//             for (int j = i + 1; j < n; j++) {
//                 sum += nums[j];
//                 if (sum % k == 0) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };