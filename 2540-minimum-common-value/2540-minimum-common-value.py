class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        
        def binarySearch(nums : List[int], num : int) -> bool:
            low , high = 0, len(nums) - 1
            while (low <= high):
                mid = low + (high - low) // 2
                if nums[mid] == num:
                    return True
                elif nums[mid] > num:
                    high = mid - 1
                else:
                    low = mid + 1
            return False

        for num in nums1:
            if binarySearch(nums2, num):
                return num
        return -1

# class Solution:
#     def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
#         st = set(nums1)
#         for num in nums2:
#             if num in st:
#                 return num
#         return -1

# class Solution:
#     def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
#         i , j , m , n = 0, 0, len(nums1), len(nums2)
#         while i < m and j < n:
#             if nums1[i] == nums2[j]:
#                 return nums1[i]
#             elif nums1[i] > nums2[j]:
#                 j += 1
#             elif nums1[i] < nums2[j]:
#                 i += 1
#         return -1