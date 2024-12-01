class Solution {
public:
    int smallestNumber(int n) {
        int ans = INT_MAX;
        for (int i = 0; i < 31; i++) {
            int val = (1 << i) - 1;
            if (val  >= n) {
                ans = min(ans, val);
            }
        }
        return ans;
    }
};