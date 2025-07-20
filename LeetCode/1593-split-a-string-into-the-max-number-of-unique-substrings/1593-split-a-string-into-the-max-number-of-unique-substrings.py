class Solution:
    def __init__(self):
        self.st = set()
        self.ans = 0

    def solve(self, s: str, i: int, t: str):
        if i == len(s):
            self.ans = max(self.ans, len(self.st))
            return
        for j in range(i, len(s)):
            t += s[j]
            if t not in self.st:
                self.st.add(t)
                self.solve(s, j + 1, "")
                self.st.discard(t)

    def maxUniqueSplit(self, s: str) -> int:
        self.solve(s, 0, "")
        return self.ans