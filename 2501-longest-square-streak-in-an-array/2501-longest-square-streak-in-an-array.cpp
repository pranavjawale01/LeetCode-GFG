class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int &x : nums) {
            int count = 0;
            while (st.count(x)) {
                count++;
                x *= x;
                if (x > 1e5) break;
            }
            if (count >= 2) ans = max(ans, count);
        }
        return ans == 0 ? -1 : ans;
    }
};