class Solution {
    public int slidingWindowCount(int[] nums, int d) {
        int i = 0, j = 0;
        int n = nums.length;
        int pairCount = 0;
        
        while (j < n) {
            while (j < n && nums[j] - nums[i] > d) {
                i++;
            }
            pairCount += (j - i);
            j++;
        }
        
        return pairCount;
    }
    public int smallestDistancePair(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int l = 0;
        int r = nums[n - 1] - nums[0];
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int countPair = slidingWindowCount(nums, mid);
            
            if (countPair < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return l;
    }
}





// class Solution {
//     public int smallestDistancePair(int[] nums, int k) {
//         int n = nums.length;
//         int maxEl = 0;
//         for (int i = 0; i < n; i++) {
//             maxEl = Math.max(maxEl, nums[i]);
//         }
//         int[] arr = new int[maxEl+1];
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 arr[Math.abs(nums[i] - nums[j])]++;
//             }
//         }
//         for (int d = 0; d < maxEl + 1; d++) {
//             k -= arr[d];
//             if (k <= 0) {
//                 return d;
//             }
//         }
//         return -1;
//     }
// }