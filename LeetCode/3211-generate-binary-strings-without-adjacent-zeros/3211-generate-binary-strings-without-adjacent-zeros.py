class Solution:
    def __init__(self):
        self.ans: List[str] = []

    def solve(self, n: int, s: str, i: int):
        if i == n:
            self.ans.append(s)
            return
        if i == 0 or s[i-1] == '1':
            self.solve(n, s + '1', i + 1)
            self.solve(n, s + '0', i + 1)
        else:
            self.solve(n, s + '1', i + 1)

    def validStrings(self, n: int) -> List[str]:
        self.ans = []
        self.solve(n, "", 0)
        return self.ans