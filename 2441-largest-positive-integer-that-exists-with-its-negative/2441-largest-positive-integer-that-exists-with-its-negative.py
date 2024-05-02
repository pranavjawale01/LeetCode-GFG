class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        nums.sort()
        low , high = 0, len(nums) - 1
        while low <= high:
            if nums[low] * (-1) == nums[high]:
                return nums[high]
            elif nums[low] * (-1) > nums[high]:
                low += 1
            else:
                high -= 1
        return -1