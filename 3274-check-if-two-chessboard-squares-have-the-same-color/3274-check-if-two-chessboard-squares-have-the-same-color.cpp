class Solution {
public:
    char solve(string s) {
        if ((s[1] - '0') % 2 == 1) {
            int t = s[0] - 'a';
            if (t % 2 == 1) {
                return 'w';
            } else {
                return 'b';
            }
        } else {
            int t = s[0] - 'a';
            if (t % 2 == 1) {
                return 'b';
            } else {
                return 'w';
            }
        }
    }
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        char c1, c2;
        c1 = solve(coordinate1);
        c2 = solve(coordinate2);
        return c1 == c2;
    }
};