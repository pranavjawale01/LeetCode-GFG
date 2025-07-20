class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x <0 :
            return False;
        y = 0
        original = x
        reverse = 0
        while(x > 0):
            y = x%10
            reverse = reverse*10 + y
            x //=10
            
        return original == reverse