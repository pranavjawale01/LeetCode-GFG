class Solution {
    public boolean canAliceWin(int[] nums) {
        int singleNum = 0, doubleNum = 0;
        for (int x : nums) {
            if (x <= 9) {
                singleNum += x;
            } else {
                doubleNum += x;
            }
        }
        if (singleNum == doubleNum) {
            return false;
        }
        return true;
    }
}