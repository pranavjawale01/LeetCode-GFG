class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        consumed = 0
        while numBottles >= numExchange:
            consumed += numExchange
            numBottles -= numExchange
            numBottles += 1
        return consumed + numBottles