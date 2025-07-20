class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int one = 0;
        for (int x : nums) {
            if (x == 1) {
                one++;
            } else {
                ans = max(ans, one);
                one = 0;
            }
        }
        ans = max(ans, one);
        return ans;
    }
};