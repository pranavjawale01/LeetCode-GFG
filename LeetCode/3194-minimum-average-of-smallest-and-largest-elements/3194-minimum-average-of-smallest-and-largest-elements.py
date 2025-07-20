class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        minEl = float('inf')
        nums.sort()
        i, j = 0, len(nums) - 1
        while i <= j:
            avg = (nums[i] + nums[j]) / 2
            minEl = min(minEl, avg)
            i += 1
            j -= 1
        return minEl