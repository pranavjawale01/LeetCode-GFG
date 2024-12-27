class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        for (int j = 1; j < n; j++) {
            int maxval = 0;
            for (int i = j - 1; i >= 0; i--) {
                maxval = max(maxval, values[i] + i);
            }
            ans = max(ans, maxval + values[j] - j);
        }
        return ans;
    }
};