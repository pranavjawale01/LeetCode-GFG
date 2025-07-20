class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        count = 0
        n = len(nums)
        
        for i in range(n - 1):
            low_bound = bisect_left(nums, lower - nums[i], i + 1, n)
            up_bound = bisect_right(nums, upper - nums[i], i + 1, n)
            count += (up_bound - low_bound)
        
        return count