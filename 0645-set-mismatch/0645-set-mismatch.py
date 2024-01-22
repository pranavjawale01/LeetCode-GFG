class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        dup = -1
        missing = -1
        
        for i in range(n):
            index = abs(nums[i]) - 1
            if nums[index] < 0:
                dup = abs(nums[i])
            else:
                nums[index] *= -1
        
        for i in range(n):
            if nums[i] > 0:
                missing = i + 1
        
        return [dup, missing]