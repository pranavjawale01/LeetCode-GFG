class Solution {
public:
    int maxOperations(string s) {
        int n = s.length(), count = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                ans += count;
                while (i < n && s[i] != '1') {
                    i++;
                }
            }
            count++;
        }
        return ans;
    }
};