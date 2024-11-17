class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        if (allZero(nums)) {
            return 0;
        }

        int low = 0, high = queries.length - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canMakeZero(nums.clone(), queries, mid)) {
                result = mid + 1; 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }

    private boolean allZero(int[] nums) {
        for (int num : nums) {
            if (num != 0) return false;
        }
        return true;
    }

    private boolean canMakeZero(int[] nums, int[][] queries, int k) {
        int n = nums.length;
        int[] diff = new int[n + 1];

        for (int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] -= val;
            if (r + 1 < n) {
                diff[r + 1] += val;
            }
        }

        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += diff[i];
            nums[i] += temp;
            if (nums[i] < 0) nums[i] = 0;
        }

        return allZero(nums);
    }
}