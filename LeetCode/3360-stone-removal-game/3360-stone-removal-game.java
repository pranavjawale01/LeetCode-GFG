class Solution {
    public boolean canAliceWin(int n) {
        int stone = 10;
        while (n >= 0) {
            if (n >= stone) {
                n -= stone;
                stone--;
            } else {
                return false;
            }
            if (n >= stone) {
                n -= stone;
                stone--;
            } else {
                return true;
            }
        }
        return true;
    }
}