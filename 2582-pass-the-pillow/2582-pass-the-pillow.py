class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        cycleLength = (n - 1) * 2
        positionInCycle = time % cycleLength
        if positionInCycle < n:
            return positionInCycle + 1
        return 2 * n - positionInCycle - 1