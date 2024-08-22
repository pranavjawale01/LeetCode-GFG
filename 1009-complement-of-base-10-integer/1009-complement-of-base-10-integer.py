class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        
        i = 31
        while i >= 0 and (n & (1 << i)) == 0:
            i -= 1
        
        while i >= 0:
            n = n ^ (1 << i)
            i -= 1
            
        return n