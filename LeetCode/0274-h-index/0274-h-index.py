class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        count = [0] * (n + 1)
        for c in citations:
            if c > n:
                count[n] += 1
            else:
                count[c] += 1
        
        ans = 0
        for i in range(n, -1, -1):
            ans += count[i]
            if ans >= i:
                return i
        return 0