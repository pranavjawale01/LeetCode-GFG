class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        count1 , count2 = 0 , 0
        vowels = ['a','e','i','o','u','A','E','I','O','U']
        
        for c in s[:len(s)//2]:
            if c in vowels:
                count1 += 1
        for c in s[len(s)//2:]:
            if c in vowels:
                count2 += 1
        return count1 == count2