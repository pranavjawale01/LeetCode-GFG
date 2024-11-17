class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        if all(x == 0 for x in nums):
            return 0

        low, high = 0, len(queries) - 1
        result = -1

        while low <= high:
            mid = low + (high - low) // 2
            if self.canMakeZero(nums[:], queries, mid):
                result = mid + 1
                high = mid - 1
            else:
                low = mid + 1

        return result

    def canMakeZero(self, nums: List[int], queries: List[List[int]], k: int) -> bool:
        n = len(nums)
        diff = [0] * (n + 1)

        for i in range(k + 1):
            l, r, val = queries[i]
            diff[l] -= val
            if r + 1 < n:
                diff[r + 1] += val

        temp = 0
        for i in range(n):
            temp += diff[i]
            nums[i] += temp
            if nums[i] < 0:
                nums[i] = 0

        return all(x == 0 for x in nums)