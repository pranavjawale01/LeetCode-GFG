class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        Set<Integer> st = new HashSet<>();
        for (int num : nums1) {
            st.add(num);
        }
        for (int num : nums2) {
            if (st.contains(num)) {
                return num;
            }
        }
        return -1;
    }
}
// class Solution {
//     public int getCommon(int[] nums1, int[] nums2) {
//         int i = 0, j = 0;
//         int n = nums1.length, m = nums2.length;
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
// }