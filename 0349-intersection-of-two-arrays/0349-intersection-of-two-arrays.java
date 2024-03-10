import java.util.*;

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();        
        for (int num : nums1) {
            set1.add(num);
        }        
        List<Integer> intersection = new ArrayList<>();
        for (int num : nums2) {
            if (set1.contains(num)) {
                intersection.add(num);
                set1.remove(num);
            }
        }
        int[] ans = new int[intersection.size()];
        for (int i = 0; i < intersection.size(); i++) {
            ans[i] = intersection.get(i);
        }        
        return ans;
    }
}
// import java.util.*;

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