class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n , count = len(nums) , len(nums)
        i = 0
        while i < n - 2:
            if nums[i] == nums[i+1] == nums[i+2]:
                for j in range(i , n - 1):
                    nums[j] = nums[j+1]
                n -= 1
                count -= 1
            else:
                i += 1
        return count