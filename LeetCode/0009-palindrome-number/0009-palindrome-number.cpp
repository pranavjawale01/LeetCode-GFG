class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        long int y=0, reverse=0, original=x;
        while(x > 0)
        {
            y = x%10;
            reverse = reverse*10 + y;
            x /= 10;
        }
        return original == reverse;
    }
};