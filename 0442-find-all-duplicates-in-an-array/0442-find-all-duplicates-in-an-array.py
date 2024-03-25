class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr = []
        for i in range(n):
            index = abs(nums[i]) - 1
            if nums[index] < 0:
                arr.append(abs(nums[i]))
            else:
                nums[index] *= (-1)
        return arr

# class Solution:
#     def findDuplicates(self, nums: List[int]) -> List[int]:
#         ans = []
#         nums.sort()
#         for i in range(1, len(nums)):
#             if nums[i] == nums[i-1]:
#                 ans.append(nums[i-1])
#         return ans

# # class Solution:
# #     def findDuplicates(self, nums: List[int]) -> List[int]:
# #         ans = []
# #         mp = defaultdict(int)
# #         for num in nums:
# #             mp[num] += 1
# #             if mp[num] > 1:
# #                 ans.append(num)
# #         return ans