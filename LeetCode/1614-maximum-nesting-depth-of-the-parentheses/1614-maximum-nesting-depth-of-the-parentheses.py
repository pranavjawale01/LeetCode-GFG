class Solution:
    def maxDepth(self, s: str) -> int:
        count , ans = 0 , 0
        for c in s:
            if c == '(':
                count += 1
                ans = max(ans, count)
            elif c == ')':
                count -= 1
        return ans