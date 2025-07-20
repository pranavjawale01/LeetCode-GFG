class Solution {
    public int countAsterisks(String s) {
        int count = 0;
        int ast = 0;
        for (char c : s.toCharArray()) {
            if (c == '*' && ast == 0) {
                count++;
            }
            if (c == '|') {
                ast ^= 1;
            }
        }
        return count;
    }
}