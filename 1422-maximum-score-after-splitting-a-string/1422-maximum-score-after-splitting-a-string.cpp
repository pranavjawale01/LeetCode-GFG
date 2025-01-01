class Solution {
public:
    int maxScore(string s) {
        int ans = 0, one = 0, zero = 0;
        for (char &c : s) if (c == '1') one++;
        for (char &c : s) {
            if (c == '1') one--;
            else zero++;
            ans = max(ans, zero + one);
        }
        return ans;
    }
};