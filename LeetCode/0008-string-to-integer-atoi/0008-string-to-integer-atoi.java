class Solution {
    public int myAtoi(String s) {
        int len = s.length();
        if(len==0)
        {
            return 0;
        }
        int i=0, sign=1, result=0;
        while(i<len && s.charAt(i)==' ')
        {
            i++;
        }
        if(i<len && (s.charAt(i)=='+' || s.charAt(i)=='-'))
        {
            if(s.charAt(i)=='-')
            {
                sign=-1;
            }
            i++;
        }
        while(i<len && Character.isDigit(s.charAt(i)))
        {
            int digit = s.charAt(i)-'0';
            if(result > Integer.MAX_VALUE/10 || (result == Integer.MAX_VALUE/10 && digit > Integer.MAX_VALUE % 10))
            {                
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            result = result * 10 + digit;
            i++;
        }
        return result * sign;  
    }
};