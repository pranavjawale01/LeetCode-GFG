class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        int maxLen = 0;
        for (auto x : st) {
            if (st.find(x - 1) == st.end()) {
                int count = 1;
                int num = x;
                while (st.find(num+1) != st.end()) {
                    num++;
                    count++;
                }
                maxLen = max(maxLen, count);
            }
        }
        return maxLen;
    }
};