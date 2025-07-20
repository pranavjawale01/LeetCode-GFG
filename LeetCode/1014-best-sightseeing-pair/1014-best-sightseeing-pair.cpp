class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int maxval = values[0] + 0;
        for (int j = 1; j < n; j++) {
            int x = values[j] - j;
            int y = maxval;
            ans = max(ans, x + y);
            maxval = max(maxval, values[j] + j);
        }
        return ans;
    }
};






// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int n = values.size();
//         vector<int> vec(n, 0);
//         vec[0] = values[0] + 0;
//         for (int i = 1; i < n; i++) {
//             vec[i] = max(values[i] + i, vec[i-1]);
//         }
//         int ans = 0;
//         for (int j = 1; j < n; j++) {
//             int x = values[j] - j;
//             int y = vec[j-1];
//             ans = max(ans, x + y);
//         }
//         return ans;
//     }
// };






// // class Solution {
// // public:
// //     int maxScoreSightseeingPair(vector<int>& values) {
// //         int n = values.size();
// //         int ans = 0;
// //         for (int j = 1; j < n; j++) {
// //             int maxval = 0;
// //             for (int i = j - 1; i >= 0; i--) {
// //                 maxval = max(maxval, values[i] + i);
// //             }
// //             ans = max(ans, maxval + values[j] - j);
// //         }
// //         return ans;
// //     }
// // };