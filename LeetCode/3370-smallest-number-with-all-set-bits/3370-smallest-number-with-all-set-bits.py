class Solution:
    def smallestNumber(self, n: int) -> int:
        ans = float('inf')
        for i in range(31):
            val = (1 << i) - 1
            if val >= n:
                ans = min(ans, val)
        return ans