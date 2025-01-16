class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans = 0;
        if (n % 2 == m % 2) {
            if (n % 2 == 0) {
                ans = 0;
            } else {
                for (int i = 0; i < n; i++) ans ^= nums1[i];
                for (int i = 0; i < m; i++) ans ^= nums2[i];
            }
        } else {
            if (n % 2 == 1) {
                for (int i = 0; i < m; i++) ans ^= nums2[i];
            } else {
                for (int i = 0; i < n; i++) ans ^= nums1[i];
            }
        }
        return ans;
    }
};







// class Solution {
// public:
//     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size();
//         int ans = 0;
//         if (m % 2 != 0) {
//             for (int &x : nums2) {
//                 ans ^= x;
//             }
//         }
//         if (n % 2 != 0) {
//             for (int &x : nums1) {
//                 ans ^= x;
//             }
//         }
//         return ans;
//     }
// };






// // class Solution {
// // public:
// //     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
// //         int m = nums1.size(), n = nums2.size();
// //         unordered_map<int, long> mp;
// //         for (int x : nums1) mp[x] += n;
// //         for (int x : nums2) mp[x] += m;
// //         int ans = 0;
// //         for (auto &x : mp) {
// //             int val = x.first;
// //             int frq = x.second;
// //             if (frq % 2 != 0) ans ^= val;
// //         }
// //         return ans;
// //     }
// // };