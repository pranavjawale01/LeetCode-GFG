class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        for i in range(n - 1):
            if nums[i] == nums[i + 1] and nums[i] != 0:
                nums[i] *= 2
                nums[i + 1] = 0

        non_zero_pos = 0
        for i in range(n):
            if nums[i] != 0:
                nums[i], nums[non_zero_pos] = nums[non_zero_pos], nums[i]
                non_zero_pos += 1

        return nums