class Solution {
    public int specialArray(int[] nums) {
        int n = nums.length;
        int[] arr = new int[n+1];
        for (int i = 0; i < n; i++) {
            arr[Math.min(n, nums[i])]++;
        }
        int cum_sum = 0;
        for (int i = n; i >= 0; i--) {
            cum_sum += arr[i];
            if (i == cum_sum) {
                return i;
            }
        }
        return -1;
    }
}



// class Solution {
//     private int lower_bound(int[] nums, int mid_x) {
//         int low = 0, high = nums.length;
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] < mid_x) {
//                 low = mid + 1;
//             } else {
//                 high = mid;
//             }
//         }
//         return low;
//     }
//     public int specialArray(int[] nums) {
//         Arrays.sort(nums);
//         int n = nums.length;
//         int l = 0, r = n;
//         while (l <= r) {
//             int mid_x = l + (r - l) / 2;
//             int idx = lower_bound(nums, mid_x);
//             int count = n - idx;
//             if (count == mid_x) {
//                 return mid_x;
//             } else if (count > mid_x) {
//                 l = mid_x + 1;
//             } else {
//                 r = mid_x - 1;
//             }
//         }
//         return -1;
//     }
// }




// class Solution {
//     private int lowerBound(int[] nums, int x) {
//         int low = 0, high = nums.length;
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] < x) {
//                 low = mid + 1;
//             } else {
//                 high = mid;
//             }
//         }
//         return low;
//     }
//     public int specialArray(int[] nums) {
//         Arrays.sort(nums);
//         int n = nums.length;
//         for (int x = 0; x <= n; x++) {
//             int idx = lowerBound(nums, x);
//             int count = n - idx;
//             if (count == x) {
//                 return x;
//             }
//         }
//         return -1;
//     }
// }