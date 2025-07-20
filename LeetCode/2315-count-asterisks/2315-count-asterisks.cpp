class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        int ast = 0;
        for (char c : s) {
            if (c == '*' && ast == 0) {
                count++;
            }
            if (c == '|') {
                ast ^= 1;
            }
        }
        return count;
    }
};