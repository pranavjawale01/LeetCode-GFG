class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        total_sum = sum(chalk)
        k %= total_sum
        
        for i, c in enumerate(chalk):
            if k < c:
                return i
            k -= c
            
        return 0