class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        count = 0 
        vowels = ['a','e','i','o','u','A','E','I','O','U']
        
        for c in s[:len(s)//2]:
            if c in vowels:
                count += 1
        for c in s[len(s)//2:]:
            if c in vowels:
                count -= 1
        return count == 0