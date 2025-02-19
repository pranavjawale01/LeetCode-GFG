class Solution:
    def __init__(self):
        self.ans = []

    def solve(self, n, curr):
        if len(curr) == n:
            self.ans.append(curr)
            return
        for ch in "abc":
            if curr and curr[-1] == ch:
                continue
            self.solve(n, curr + ch)

    def getHappyString(self, n: int, k: int) -> str:
        self.solve(n, "")
        return "" if len(self.ans) < k else self.ans[k - 1]