class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        while (i < n && s[i] == ' ') i++;
        bool neg = false;
        if (i < n && s[i] == '-') {
            neg = true;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }
        int ans = 0;
        while (i < n && s[i] >= '0' && s[i] <='9') {
            int digit = s[i] - '0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return neg ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            i++;
        }
        return neg ? -ans : ans;
    }
};