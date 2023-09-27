class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        unique = 1
        for i in range(1,len(nums)):
            if nums[i] != nums[i-1]:
                nums[unique] = nums[i]
                unique += 1
        return unique