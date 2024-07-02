class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {}
        for x in nums1:
            if x not in mp:
                mp[x] = 1
            else:
                mp[x] += 1
        ans = []
        for x in nums2:
            if x in mp and mp[x] > 0:
                mp[x] -= 1
                ans.append(x)
        return ans






# class Solution:
#     def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
#         nums1.sort()
#         nums2.sort()
#         m, n, i, j = len(nums1), len(nums2), 0, 0
#         ans = []
#         while i < m and j < n:
#             if nums1[i] == nums2[j]:
#                 ans.append(nums1[i])
#                 i += 1
#                 j += 1
#             elif nums1[i] > nums2[j]:
#                 j += 1
#             else:
#                 i += 1
#         return ans