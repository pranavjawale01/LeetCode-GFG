class Solution {

    private void merge(int[] nums, int low, int mid, int high) {
        int[] temp = new int[high - low + 1];
        int left = low, right = mid + 1, index = 0;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp[index++] = nums[left++];
            } else {
                temp[index++] = nums[right++];
            }
        }

        while (left <= mid) {
            temp[index++] = nums[left++];
        }

        while (right <= high) {
            temp[index++] = nums[right++];
        }

        System.arraycopy(temp, 0, nums, low, temp.length);
    }

    private int countPairs(int[] nums, int low, int mid, int high) {
        int count = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high && (long) nums[i] > 2 * (long) nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }

        return count;
    }

    private int mergeSort(int[] nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);

        return count;
    }

    public int reversePairs(int[] nums) {
        return mergeSort(nums, 0, nums.length - 1);
    }
}