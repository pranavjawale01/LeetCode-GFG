class Solution:
    def getNumOfBouquets(self, bloomDay: List[int], mid: int, k: int) -> int:
        numOfBouquets = 0
        consecutiveCount = 0
        for day in bloomDay:
            if day <= mid:
                consecutiveCount += 1
            else:
                consecutiveCount = 0
            if consecutiveCount == k:
                numOfBouquets += 1
                consecutiveCount = 0
        return numOfBouquets

    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        startDay = 0
        endDay = max(bloomDay)
        minDays = -1
        while startDay <= endDay:
            mid = startDay + (endDay - startDay) // 2
            if self.getNumOfBouquets(bloomDay, mid, k) >= m:
                minDays = mid
                endDay = mid - 1
            else:
                startDay = mid + 1
        return minDays