class Solution:
    def __init__(self):
        self.st = set()
        self.ans = ""

    def solve(self, curr, n):
        if len(curr) == n:
            if curr not in self.st:
                self.ans = curr
            return
        if self.ans:
            return

        self.solve(curr + '0', n)
        self.solve(curr + '1', n)

    def findDifferentBinaryString(self, nums: List[str]) -> str:
        self.st = set(nums)
        self.solve("", len(nums[0]))
        return self.ans