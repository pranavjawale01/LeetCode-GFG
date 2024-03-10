class Solution:
    def binarySearch(self, nums, num):
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == num:
                return True
            elif num > nums[mid]:
                low = mid + 1
            else:
                high = mid - 1
        return False
    
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        ans = set()
        for num in nums2:
            if self.binarySearch(nums1, num):
                ans.add(num)
        return list(ans)

# class Solution:
#     def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
#         s1 = set(nums1)
#         ans = []
#         for num in nums2:
#             if num in s1:
#                 ans.append(num)
#                 s1.remove(num)
#         return ans

# class Solution:
#     def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
#         s1 = set(nums1)
#         s2 = set(nums2)
#         ans = []
#         for num in s2:
#             if num in s1:
#                 ans.append(num)
#         return ans