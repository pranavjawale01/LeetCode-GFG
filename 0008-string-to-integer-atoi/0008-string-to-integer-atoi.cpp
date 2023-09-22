class Solution {
public:
    int myAtoi(string s) 
    {
        int len = s.size();
        if(len==0)
        {
            return 0;
        }
        int i = 0, sign = 1, result = 0;
        while (i < len && s[i] == ' ') 
        {
            i++;
        }
        if (i < len && (s[i] == '+' || s[i] == '-')) 
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < len && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) 
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }
        return result * sign;
    }
};