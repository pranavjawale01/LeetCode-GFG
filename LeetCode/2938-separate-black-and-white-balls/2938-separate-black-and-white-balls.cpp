class Solution {
public:
    long long minimumSteps(string s) {
        int white = 0;
        long long ans = 0;
        int n = s.size();
        
        for (int j = 0; j < n; j++) {
            if (s[j] == '0') {
                ans += white;
            }
            if (s[j] == '1') {
                white++;
            }
        }
        
        return ans;
    }
};