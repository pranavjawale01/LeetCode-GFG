class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') count++;
        }
        string ans = "";
        for (int i = 0; i < count - 1 ; i++) {
            ans += "1";
        }
        for (int i = 0; i < n - count; i++) {
            ans += "0";
        }
        ans += "1";
        return ans;
    }
};