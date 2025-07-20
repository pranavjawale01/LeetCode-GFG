class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        arr = [0] * 2001
        result = -1
        for num in nums:
            if arr[-num + 1000] == 1:
                result = max(result, abs(num))
            arr[num + 1000] = 1
        return result

        

# class Solution:
#     def findMaxK(self, nums: List[int]) -> int:
#         st = set()
#         ans = -1
#         for num in nums:
#             if (-num) in st:
#                 ans = max(ans, abs(num))
#             else:
#                 st.add(num)
#         return ans


# class Solution:
#     def findMaxK(self, nums: List[int]) -> int:
#         nums.sort()
#         low , high = 0, len(nums) - 1
#         while low <= high:
#             if nums[low] * (-1) == nums[high]:
#                 return nums[high]
#             elif nums[low] * (-1) > nums[high]:
#                 low += 1
#             else:
#                 high -= 1
#         return -1