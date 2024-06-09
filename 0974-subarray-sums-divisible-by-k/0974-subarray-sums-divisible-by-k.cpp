class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;
        int result = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0) {
                rem += k;
            }
            if (mp.find(rem) != mp.end()) {
                result += mp[rem];
            }
            mp[rem]++;
        }
        return result;
    }
};



// TLE
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for (int i = 1; i < n; i++) {
//             nums[i] += nums[i-1];
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int sum = (i == 0) ? nums[j] : nums[j] - nums[i-1];
//                 if (sum % k == 0) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };



// TLE
// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
//                 if (sum % k == 0) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };