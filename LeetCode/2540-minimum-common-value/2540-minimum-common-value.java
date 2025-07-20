class Solution {
    public boolean binarySearch(int[] nums, int num) {
        int low = 0, high = nums.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == num) {
                return true;
            } else if (nums[mid] > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
    public int getCommon(int[] nums1, int[] nums2) {
        for (int num : nums1) {
            if (binarySearch(nums2, num)) {
                return num;
            }
        }
        return -1;
    }
}

// class Solution {
//     public int getCommon(int[] nums1, int[] nums2) {
//         Set<Integer> st = new HashSet<>();
//         for (int num : nums1) {
//             st.add(num);
//         }
//         for (int num : nums2) {
//             if (st.contains(num)) {
//                 return num;
//             }
//         }
//         return -1;
//     }
// }

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