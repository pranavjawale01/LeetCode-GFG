class Solution:
    def binarySearch(self, workerTime: int, availableTime: int, mountainHeight: int) -> int:
        low, high, maxHeight = 0, mountainHeight, 0
        while low <= high:
            mid = low + (high - low) // 2
            requiredTime = workerTime * (mid * (mid + 1)) // 2
            if requiredTime <= availableTime:
                maxHeight = mid
                low = mid + 1
            else:
                high = mid - 1
        return maxHeight
    
    def solve(self, mountainHeight: int, workerTimes: List[int], time: int) -> bool:
        total = 0
        for workerTime in workerTimes:
            total += self.binarySearch(workerTime, time, mountainHeight)
            if total >= mountainHeight:
                return True
        return total >= mountainHeight
    
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        low, high = 0, 10**18
        while low < high:
            mid = low + (high - low) // 2
            if self.solve(mountainHeight, workerTimes, mid):
                high = mid
            else:
                low = mid + 1
        return low