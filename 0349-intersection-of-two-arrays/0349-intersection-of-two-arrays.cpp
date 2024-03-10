class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(begin(nums1), end(nums1));
        unordered_set<int> s2(begin(nums2), end(nums2));
        vector<int> ans;
        for (int num : s2) {
            if (s1.find(num) != s1.end()) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};