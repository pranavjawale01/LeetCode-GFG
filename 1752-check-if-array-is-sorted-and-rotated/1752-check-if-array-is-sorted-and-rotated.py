class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)

        for r in range(n):
            sorted_nums = nums[r:] + nums[:r]
            if sorted_nums == sorted(sorted_nums):
                return True

        return False