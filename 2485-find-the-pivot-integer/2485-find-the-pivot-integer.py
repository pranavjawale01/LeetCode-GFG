class Solution:
    def pivotInteger(self, n: int) -> int:
        lSum , rSum = 0, 0
        for i in range(1, n+1):
            lSum += i
            for j in range(i, n+1):
                rSum += j
            if rSum == lSum:
                return i
            rSum = 0
        return -1