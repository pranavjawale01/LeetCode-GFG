class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = count(s.begin(), s.end(), '1');
        int maxScore = 0;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }
            maxScore = max(maxScore, zeros + ones);
        }
        return maxScore;
    }
};