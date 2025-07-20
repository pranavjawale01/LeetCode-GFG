class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = nums[0]
        for i in range(1, len(nums)):
            ans ^= nums[i]
        return bin(ans ^ k).count('1')