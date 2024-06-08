class Solution:
    def clearDigits(self, s: str) -> str:
        ans = ""
        for c in s:
            if c.isdigit():
                ans = ans[:-1]
            else:
                ans += c
        return ans