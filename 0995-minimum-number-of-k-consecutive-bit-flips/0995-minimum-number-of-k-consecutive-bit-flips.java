class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int flips = 0;
        boolean[] isFlipped = new boolean[n];
        int flipCountFromPastForCurri = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k && isFlipped[i-k]) {
                flipCountFromPastForCurri--;
            }
            if (flipCountFromPastForCurri % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipCountFromPastForCurri++;
                isFlipped[i] = true;
                flips++;
            }
        }
        return flips;
    }
}