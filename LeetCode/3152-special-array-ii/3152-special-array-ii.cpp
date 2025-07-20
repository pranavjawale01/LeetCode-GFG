class Solution {
public:
    bool solve(vector<int> &vi, int sp, int ep) {
        int l = 0, r = vi.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vi[mid] < sp) {
                l = mid + 1;
            } else if (vi[mid] > ep) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size(), n = nums.size();
        vector<int> vi;
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i-1] % 2) {
                vi.push_back(i);
            }
        }
        vector<bool> ans(m, false);
        for (int i = 0; i < m; i++) {
            int s = queries[i][0], e = queries[i][1];
            if (solve(vi, s+1, e) == false) {
                ans[i] = true;
            }
        }
        return ans;
    }
};







// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         int m = queries.size();
//         vector<int> idx(n);
//         int i = 0, j = 0;
//         while (i < n) {
//             if (j < i) j = i;
//             while (j + 1 < n && nums[j] % 2 != nums[j+1] % 2) {
//                 j++;
//             }
//             idx[i] = j;
//             i++;
//         }
//         vector<bool> ans(m, false);
//         for (int i = 0; i < m; i++) {
//             int s = queries[i][0], e = queries[i][1];
//             if (e <= idx[s]) {
//                 ans[i] = true;
//             }
//         }
//         return ans;
//     }
// };








// // class Solution {
// // public:
// //     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
// //         int n = nums.size();
// //         int m = queries.size();

// //         vector<int> cumSum(n, 0);
// //         cumSum[0] = 0;

// //         for (int i = 1; i < n; i++) {
// //             if (nums[i] % 2 == nums[i - 1] % 2) {
// //                 cumSum[i] = cumSum[i - 1] + 1;
// //             } else {
// //                 cumSum[i] = cumSum[i - 1];
// //             }
// //         }

// //         vector<bool> result(m, false);
// //         int i = 0;
// //         for (vector<int>& query : queries) {
// //             int start = query[0];
// //             int end = query[1];

// //             if (cumSum[end] - cumSum[start] == 0) {
// //                 result[i] = true;
// //             }
// //             i++;
// //         }

// //         return result;
// //     }
// // };