class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int l = 0, r = n - 1;
        int maxScore = 0, score = 0;
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                score++;
                l++;
                maxScore = max(maxScore, score);
            } else if (score >= 1) {
                score--;
                power += tokens[r];
                r--;
            } else {
                return maxScore;
            }
        }
        return maxScore;
    }
};