class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }

        vector<int> lis;
        for (int height : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), height);
            if (it == lis.end()) {
                lis.push_back(height);
            } else {
                *it = height;
            }
        }

        return lis.size();
    }
};



// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         sort(envelopes.begin(), envelopes.end(), [](
//             const vector<int> &a, const vector<int> &b){
//                 return (a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]);
//             });
//         int n = envelopes.size();
//         vector<int> dp(n, 1);
//         int count = 1;
//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
//                     if (dp[i] < dp[j] + 1) {
//                         dp[i] = dp[j] + 1;
//                         count = max(count, dp[i]);
//                     }
//                 } 
//             }
//         }
//         return count;
//     }
// };