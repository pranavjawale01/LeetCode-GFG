class Solution {
    private char solve(String s) {
        if ((s.charAt(1) - '0') % 2 == 1) {
            int t = s.charAt(0) - 'a';
            if (t % 2 == 1) {
                return 'w';
            } else {
                return 'b';
            }
        } else {
            int t = s.charAt(0) - 'a';
            if (t % 2 == 1) {
                return 'b';
            } else {
                return 'w';
            }
        }
    }

    public boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        char c1 = solve(coordinate1);
        char c2 = solve(coordinate2);
        return c1 == c2;
    }
}