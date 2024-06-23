class Solution {
    public int minOperations(int[] nums) {
        int flip = 0;
        int exp = 1;
        for (int num : nums) {
            if (num != exp) {
                flip++;
                exp = 1 - exp;
            }
        }
        return flip;
    }
}