class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        n = len(nums)
        maxVal = (1 << maximumBit) - 1
        xorAll = 0
        for x in nums:
            xorAll ^= x
        ans = []
        for i in range(n):
            ans.append(maxVal ^ xorAll)
            xorAll ^= nums[n - i - 1]
        return ans