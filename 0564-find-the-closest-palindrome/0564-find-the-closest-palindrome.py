class Solution:
    def nearestPalindromic(self, n: str) -> str:
        length = len(n)
        prefix = int(n[:(length + 1) // 2])
        candidates = set()
        
        for i in range(-1, 2):
            p = str(prefix + i)
            pal = p + p[::-1][length % 2:]
            candidates.add(int(pal))
        
        candidates.add(10**(length - 1) - 1)
        candidates.add(10**length + 1)
        
        num = int(n)
        min_diff = float('inf')
        result = 0
        
        for candidate in candidates:
            if candidate != num:
                diff = abs(candidate - num)
                if diff < min_diff or (diff == min_diff and candidate < result):
                    min_diff = diff
                    result = candidate
        
        return str(result)