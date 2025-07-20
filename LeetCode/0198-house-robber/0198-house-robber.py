class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        
        if n == 0:
            return 0
        if n == 1:
            return nums[0]

        prev2 = 0
        prev1 = nums[0]

        for i in range(2, n + 1):
            steal = nums[i-1] + prev2
            skip = prev1
            current = max(steal, skip)
            prev2 = prev1
            prev1 = current

        return current