class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int m = nums1.length, n = nums2.length;
        int i = 0, j = 0;
        List<Integer> ans = new ArrayList<>();
        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                ans.add(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        int[] arr = new int[ans.size()];
        for (int k = 0; k < ans.size(); k++) {
            arr[k] = ans.get(k);
        }
        return arr;
    }
}