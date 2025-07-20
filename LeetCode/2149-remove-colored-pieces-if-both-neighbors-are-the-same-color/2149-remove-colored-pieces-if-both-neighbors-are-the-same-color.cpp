class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length(), c1 = 0, c2 = 0;
        if (n < 3) {
            return false;
        }
        for (int i = 1; i < n - 1; i++) {
            if ((colors[i] == colors[i - 1]) && (colors[i] == colors[i + 1]) && (colors[i] == 'A')) {
                c1 += 1;
            }
            if ((colors[i] == colors[i - 1]) && (colors[i] == colors[i + 1]) && (colors[i] == 'B')) {
                c2 += 1;
            }
        }
        return c1 > c2;
    }
};