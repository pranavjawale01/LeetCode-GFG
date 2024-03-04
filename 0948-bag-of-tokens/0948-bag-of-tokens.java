class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int n = tokens.length;
        int l = 0, r = n - 1, score = 0, maxScore = 0;
        Arrays.sort(tokens);
        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                l++;
                score++;
                maxScore = Math.max(maxScore, score);
            } else if (score >= 1) {
                power += tokens[r];
                r--;
                score--;
            } else {
                return maxScore;
            }
        }
        return maxScore;
    }
}