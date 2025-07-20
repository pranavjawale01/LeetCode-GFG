class Solution:
    def solve(self, maxBallsInBag, nums, maxOperations):
        totalOperations = 0
        for x in nums:
            operations = math.ceil(x / maxBallsInBag) - 1
            totalOperations += operations
            if totalOperations > maxOperations:
                return False
        return True

    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        l, r = 1, max(nums)
        ans = r
        while l <= r:
            mid = l + (r - l) // 2
            if self.solve(mid, nums, maxOperations):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans