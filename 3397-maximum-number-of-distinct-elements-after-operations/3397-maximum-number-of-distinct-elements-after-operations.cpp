class Solution {
public:
    #define all(x) x.begin(), x.end()
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(all(nums));
        unordered_set<int> st;
        int back = -k;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int temp = max(back + 1, nums[i] - k);
            if (temp <= nums[i] + k) {
                st.insert(temp);
                back = temp;
            }
        }
        return st.size();
    }
};