class Solution:
    def __init__(self):
        self.ans = []
        self.vis = []

    def solve(self, i: int, n: int) -> bool:
        if i >= len(self.ans):
            return True
        if self.ans[i] != -1:
            return self.solve(i + 1, n)

        for num in range(n, 0, -1):
            if self.vis[num]:
                continue
            self.vis[num] = True
            self.ans[i] = num

            if num == 1:
                if self.solve(i + 1, n):
                    return True
            else:
                j = i + num
                if j < len(self.ans) and self.ans[j] == -1:
                    self.ans[j] = num
                    if self.solve(i + 1, n):
                        return True
                    self.ans[j] = -1

            self.vis[num] = False
            self.ans[i] = -1
        return False

    def constructDistancedSequence(self, n: int) -> List[int]:
        self.ans = [-1] * (2 * n - 1)
        self.vis = [False] * (n + 1)
        self.solve(0, n)
        return self.ans