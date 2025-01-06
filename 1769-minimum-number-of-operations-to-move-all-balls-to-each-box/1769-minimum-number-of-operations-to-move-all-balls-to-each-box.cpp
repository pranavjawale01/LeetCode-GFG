class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int cumVal = 0, cumSum = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = cumSum;
            cumVal += boxes[i] == '0' ? 0 : 1;
            cumSum += cumVal;
        }
        cumVal = cumSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += cumSum;
            cumVal += boxes[i] == '0' ? 0 : 1;
            cumSum += cumVal;
        }
        return ans;
    }
};








// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         int n = boxes.size();
//         vector<int> ans(n, 0);
//         for (int i = 0; i < n; i++) {
//             if (boxes[i] == '1') {
//                 for (int j = 0; j < n; j++) {
//                     ans[j] += abs(j - i);
//                 }
//             }
//         }
//         return ans;
//     }
// };