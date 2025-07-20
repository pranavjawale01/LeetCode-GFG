class Solution:
    def makeGood(self, s: str) -> str:
        ans = ""
        for ch in s:
            if ans and (ord(ans[-1]) + 32 == ord(ch) or ord(ans[-1]) - 32 == ord(ch)):
                ans = ans[:-1]
            else:
                ans += ch
        return ans