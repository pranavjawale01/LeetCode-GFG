class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] ans = new int[n];
        int i = 0, j = n - 1;
        int x = 0, y = n - 1;

        while (i < n && j >= 0) {
            if (nums[i] < pivot) {
                ans[x] = nums[i];
                x++;
            }
            if (nums[j] > pivot) {
                ans[y] = nums[j];
                y--;
            }
            i++;
            j--;
        }

        while (x <= y) {
            ans[x] = pivot;
            x++;
        }

        return ans;
    }
}