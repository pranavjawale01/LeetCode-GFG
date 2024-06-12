class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        int len = 1;
        for (int i = 0; i < n - 1; i++) {
            if (pairs[i][1] < pairs[i+1][0]) {
                len++;
            } else {
                pairs[i+1][1] = pairs[i][1];
            }
        }
        return len;
    }
};