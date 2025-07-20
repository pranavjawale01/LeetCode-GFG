class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)
        for i in range(n):
            rem = nums[i] % 3
            if rem == 1:
                count += 1
            elif rem == 2:
                count += 1
        return count