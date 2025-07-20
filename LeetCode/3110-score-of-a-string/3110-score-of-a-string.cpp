class Solution {
public:
    int scoreOfString(string s) {
        int diff = 0;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            diff += abs((s[i] - 'a') - (s[i+1] - 'a'));
        }
        return diff;
    }
};