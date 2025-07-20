class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int num : nums) {
            int digitSum = 0;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
            ans = min(ans, digitSum);
        }
        return ans;
    }
};