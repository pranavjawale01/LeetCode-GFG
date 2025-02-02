class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        count = 0
        for i in range(n):
            if nums[i] > nums[(i+1)%n]:
                count += 1
        return count <= 1



# class Solution:
#     def check(self, nums: List[int]) -> bool:
#         n = len(nums)
#         sorted_nums = sorted(nums)

#         for r in range(n):
#             if all(sorted_nums[i] == nums[(i + r) % n] for i in range(n)):
#                 return True
#         return False




# # class Solution:
# #     def check(self, nums: List[int]) -> bool:
# #         n = len(nums)

# #         for r in range(n):
# #             sorted_nums = nums[r:] + nums[:r]
# #             if sorted_nums == sorted(sorted_nums):
# #                 return True

# #         return False