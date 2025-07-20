class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans, one = 0, 0
        for x in nums:
            if x == 1:
                one += 1
            else:
                ans = max(ans, one)
                one = 0
        ans = max(ans, one)
        return ans