class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int x : nums1) {
            mp[x]++;
        }
        int n = nums2.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mp[nums2[i]] > 0) {
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};





// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         int m = nums1.size(), n = nums2.size();
//         int i = 0, j = 0;
//         while (i < m && j < n) {
//             if (nums1[i] == nums2[j]) {
//                 ans.push_back(nums1[i]);
//                 i++;
//                 j++;
//             } else if (nums1[i] > nums2[j]) {
//                 j++;
//             } else {
//                 i++;
//             }
//         }
//         return ans;
//     }
// };