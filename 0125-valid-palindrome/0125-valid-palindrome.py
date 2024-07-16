class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        
        filtered = [c for c in s if c.isalnum()]
        
        i, j = 0, len(filtered) - 1
        while i < j:
            if filtered[i] != filtered[j]:
                return False
            i += 1
            j -= 1
        
        return True