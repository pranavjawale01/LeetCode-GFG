class Solution {
public:
    int solve(vector<int> &nums, int k) {
        int count = 0, ans = 0, start = 0, end = 0;
        int n = nums.size();
        while (end < n) {
            if (nums[end] % 2 == 1) {
                count++;
            }
            while (count > k) {
                if (nums[start] % 2 == 1) {
                    count--;
                }
                start++;
            }
            ans += end - start + 1;
            end++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};




// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         int odd = 0;
//         int count = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             if (nums[i] % 2 == 1) {
//                 odd++;
//             }
//             if (odd == k) {
//                 count++;
//             }
//             if (mp.find(odd - k) != mp.end()) {
//                 count += mp[odd - k];
//             }
//             if (mp.find(odd) != mp.end()) {
//                 mp[odd]++;
//             } else {
//                 mp[odd] = 1;
//             }
//         }
//         return count;
//     }
// };




// TLE
// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int count = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             int odd = 0;
//             for (int j = i; j < n; j++) {
//                 if (nums[j] % 2 != 0) {
//                     odd++;
//                 }
//                 if (odd == k) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };