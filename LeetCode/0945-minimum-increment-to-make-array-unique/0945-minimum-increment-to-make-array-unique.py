class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        moves = 0
        for i in range(1, n):
            if nums[i] <= nums[i-1]:
                moves += (nums[i-1] - nums[i] + 1)
                nums[i] = nums[i-1] + 1
        return moves