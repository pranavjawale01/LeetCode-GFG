class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            index = abs(nums[i]) - 1
            if nums[index] < 0:
                return abs(nums[i])
            nums[index] = nums[index] * (-1)
        return -1

# class Solution:
#     def findDuplicate(self, nums: List[int]) -> int:
#         mp = defaultdict(int)
#         for num in nums:
#             mp[num] += 1
#             if mp[num] > 1:
#                 return num
#         return -1