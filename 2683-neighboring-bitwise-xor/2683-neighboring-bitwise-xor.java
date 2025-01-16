class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int XOR = 0;
        for (int x : derived) {
            XOR ^= x;
        }
        return XOR == 0;
    }
}