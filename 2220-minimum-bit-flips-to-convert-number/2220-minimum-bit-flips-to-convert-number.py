class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        count = 0
        for _ in range(32):
            if (start & 1) != (goal & 1):
                count += 1
            start >>= 1
            goal >>= 1
        return count