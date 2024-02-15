class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        n = len(nums)
        cum_sum, perimeter = 0, 0
        nums.sort()

        for i in range(n):
            if nums[i] < cum_sum:
                perimeter = nums[i] + cum_sum
            cum_sum += nums[i]
        
        if perimeter == 0:
            return -1
        else:
            return perimeter