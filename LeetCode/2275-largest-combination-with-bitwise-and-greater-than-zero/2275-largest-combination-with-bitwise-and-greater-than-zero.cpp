class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(32, 0);
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            for (int &x : candidates) {
                if (x & 1 << i) {
                    count[i]++;
                }
            }
            ans = max(ans, count[i]);
        }
        return ans;
    }
};