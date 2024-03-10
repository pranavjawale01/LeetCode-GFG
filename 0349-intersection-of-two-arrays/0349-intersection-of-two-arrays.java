class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        List<Integer> ansList = new ArrayList<>();
        int i = 0, j = 0;
        int m = nums1.length, n = nums2.length;
        
        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                ansList.add(nums1[i]);
                while (i < m - 1 && nums1[i] == nums1[i + 1]) {
                    i++;
                } 
                while (j < n - 1 && nums2[j] == nums2[j + 1]) {
                    j++;
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        int[] ans = new int[ansList.size()];
        for (int k = 0; k < ansList.size(); k++) {
            ans[k] = ansList.get(k);
        }
        
        return ans;
    }
}

// class Solution {
//     public boolean binarySearch(int[] nums, int num) {
//         int low = 0, high = nums.length - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] == num) {
//                 return true;
//             } else if (num > nums[mid]) {
//                 low = mid + 1;
//             } else {
//                 high = mid - 1;
//             }
//         }
//         return false;
//     }
    
//     public int[] intersection(int[] nums1, int[] nums2) {
//         Arrays.sort(nums1);
//         Set<Integer> ans = new HashSet<>();
//         for (int num : nums2) {
//             if (binarySearch(nums1, num)) {
//                 ans.add(num);
//             }
//         }
//         int[] output = new int[ans.size()];
//         int i = 0;
//         for (int num : ans) {
//             output[i++] = num;
//         }
//         return output;
//     }
// }

// class Solution {
//     public int[] intersection(int[] nums1, int[] nums2) {
//         Set<Integer> set1 = new HashSet<>();        
//         for (int num : nums1) {
//             set1.add(num);
//         }        
//         List<Integer> intersection = new ArrayList<>();
//         for (int num : nums2) {
//             if (set1.contains(num)) {
//                 intersection.add(num);
//                 set1.remove(num);
//             }
//         }
//         int[] ans = new int[intersection.size()];
//         for (int i = 0; i < intersection.size(); i++) {
//             ans[i] = intersection.get(i);
//         }        
//         return ans;
//     }
// }


// class Solution {
//     public int[] intersection(int[] nums1, int[] nums2) {
//         Set<Integer> set1 = new HashSet<>();
//         Set<Integer> set2 = new HashSet<>();
        
//         for (int num : nums1) {
//             set1.add(num);
//         }
        
//         for (int num : nums2) {
//             set2.add(num);
//         }
        
//         List<Integer> intersection = new ArrayList<>();
        
//         for (int num : set2) {
//             if (set1.contains(num)) {
//                 intersection.add(num);
//             }
//         }
        
//         int[] ans = new int[intersection.size()];
//         for (int i = 0; i < intersection.size(); i++) {
//             ans[i] = intersection.get(i);
//         }
        
//         return ans;
//     }
// }