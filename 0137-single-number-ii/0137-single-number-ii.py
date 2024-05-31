class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            ones = 0
            for num in nums:
                if num & 1 << i:
                    ones += 1
            if ones % 3 != 0:
                ans |= 1 << i
        return ans

# class Solution:
#     def singleNumber(self, nums: List[int]) -> int:
#         ones, twos, threes = 0, 0, 0
#         for num in nums:
#             twos |= ones & num
#             ones ^= num
#             threes = ones & twos
#             ones &= ~threes
#             twos &= ~threes
#         return ones