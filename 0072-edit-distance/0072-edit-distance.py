class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
        self.memo = []

    def solve(self, s1: str, s2: str, i: int, j: int) -> int:
        if i == self.m:
            return self.n - j
        elif j == self.n:
            return self.m - i
        if self.memo[i][j] != -1:
            return self.memo[i][j]
        if s1[i] == s2[j]:
            self.memo[i][j] = self.solve(s1, s2, i + 1, j + 1)
        else:
            ins = 1 + self.solve(s1, s2, i, j + 1)
            dels = 1 + self.solve(s1, s2, i + 1, j)
            rep = 1 + self.solve(s1, s2, i + 1, j + 1)
            self.memo[i][j] = min(ins, dels, rep)
        return self.memo[i][j]

    def minDistance(self, word1: str, word2: str) -> int:
        self.m = len(word1)
        self.n = len(word2)
        self.memo = [[-1 for _ in range(self.n + 1)] for _ in range(self.m + 1)]
        return self.solve(word1, word2, 0, 0)