class Solution {
    public long countSubarrays(int[] nums, int k) {
        int maxE = Arrays.stream(nums).max().getAsInt();
        int i = 0, j = 0, n = nums.length, countMax = 0;
        long result = 0;
        while (j < n) {
            if (nums[j] == maxE) {
                countMax++;
            }
            while (countMax >= k) {
                result += n - j;
                if (nums[i] == maxE) {
                    countMax--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
}