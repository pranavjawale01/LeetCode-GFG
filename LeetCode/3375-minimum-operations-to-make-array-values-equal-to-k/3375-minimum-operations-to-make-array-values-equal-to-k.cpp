class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int m = *min_element(nums.begin(), nums.end());
        if (m < k) return -1;
        return st.size() + (m == k ? -1 : 0);
    }
};