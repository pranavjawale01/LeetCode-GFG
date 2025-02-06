class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto &x : mp) {
            ans += (x.second * (x.second - 1)) / 2;
        }
        return ans * 8;
    }
};



// class Solution {
// public:
//     int tupleSameProduct(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = n - 1; j > i; j--) {
//                 int val = nums[i] * nums[j];
//                 unordered_set<int> st;
//                 for (int k = i + 1; k < j; k++) {
//                     if (val % nums[k] == 0) {
//                         int data = val / nums[k];
//                         if (st.count(data)) {
//                             count++;
//                         }
//                         st.insert(nums[k]);
//                     }
//                 }
//             }
//         }
//         return count * 8;
//     }
// };








// // TLE
// // class Solution {
// // public:
// //     int tupleSameProduct(vector<int>& nums) {
// //         sort(nums.begin(), nums.end());
// //         int n = nums.size();
// //         int count = 0;
// //         for (int i = 0; i < n; i++) {
// //             for (int j = n - 1; j > i; j--) {
// //                 for (int k = i + 1; k < j; k++) {
// //                     for (int l = j - 1; l > k; l--) {
// //                         int p1 = nums[i] * nums[j];
// //                         int p2 = nums[k] * nums[l];
// //                         if (p1 == p2) count++;
// //                     }
// //                 }
// //             }
// //         }
// //         return count * 8;
// //     }
// // };








// // // TLE
// // // class Solution {
// // // public:
// // //     int tupleSameProduct(vector<int>& nums) {
// // //         int count = 0;
// // //         int n = nums.size();
// // //         for (int i = 0; i < n; i++) {
// // //             for (int j = i + 1; j < n; j++) {
// // //                 for (int k = 0; k < n; k++) {
// // //                     for (int l = k + 1; l < n; l++) {
// // //                         if (i != k && i != l && j != k && j != l) {
// // //                             int p1 = nums[i] * nums[j];
// // //                             int p2 = nums[k] * nums[l];
// // //                             if (p1 == p2) {
// // //                                 count++;
// // //                             }
// // //                         }
// // //                     }
// // //                 }
// // //             }
// // //         }
// // //         return (count / 2) * 8;
// // //     }
// // // };