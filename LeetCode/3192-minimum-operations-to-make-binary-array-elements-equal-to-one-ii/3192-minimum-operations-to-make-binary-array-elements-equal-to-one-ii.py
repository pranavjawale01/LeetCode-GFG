class Solution:
    def minOperations(self, nums: List[int]) -> int:
        flip = 0
        exp = 1
        for num in nums:
            if num != exp:
                flip += 1
                exp = 1 - exp
        return flip