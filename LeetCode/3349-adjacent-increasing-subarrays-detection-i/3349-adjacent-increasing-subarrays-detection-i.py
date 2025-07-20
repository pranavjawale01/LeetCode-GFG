class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if n < 2 * k:
            return False

        for i in range(n - 2 * k + 1):
            first = True
            second = True

            for j in range(i, i + k - 1):
                if nums[j] >= nums[j + 1]:
                    first = False
                    break

            if first:
                for j in range(i + k, i + 2 * k - 1):
                    if nums[j] >= nums[j + 1]:
                        second = False
                        break

            if first and second:
                return True

        return False