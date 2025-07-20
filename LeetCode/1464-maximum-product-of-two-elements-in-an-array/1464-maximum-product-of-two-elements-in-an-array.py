class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max1 = max(nums)
        nums.remove(max1)
        max2 = max(nums)
        return (max1 - 1)*(max2 - 1)