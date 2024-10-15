class Solution:
    def minimumSteps(self, s: str) -> int:
        white = 0
        ans = 0
        n = len(s)
        for j in range(n):
            if s[j] == '0':
                ans += white
            if s[j] == '1':
                white += 1
        return ans