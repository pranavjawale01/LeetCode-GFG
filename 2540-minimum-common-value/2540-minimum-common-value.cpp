class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(begin(nums1), end(nums1));
        for (int &num : nums2) {
            if (st.find(num) != st.end()) {
                return num;
            }
        }
        return -1;
    }
};
// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0, j = 0;
//         int n = nums1.size(), m = nums2.size();
//         while (i < n && j < m) {
//             if (nums1[i] == nums2[j]) {
//                 return nums1[i];
//             } else if (nums1[i] > nums2[j]) {
//                 j++;
//             } else if (nums1[i] < nums2[j]) {
//                 i++;
//             }
//         }
//         return -1;
//     }
// };