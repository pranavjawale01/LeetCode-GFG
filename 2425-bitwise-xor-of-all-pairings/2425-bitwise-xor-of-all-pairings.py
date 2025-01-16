class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        ans = 0
        if m % 2 != 0:
            for x in nums2:
                ans ^= x
        if n % 2 != 0:
            for x in nums1:
                ans ^= x
        return ans







# class Solution:
#     def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
#         m, n = len(nums1), len(nums2)
#         mp = {}
#         for x in nums1:
#             mp[x] = mp.get(x, 0) + n
#         for x in nums2:
#             mp[x] = mp.get(x, 0) + m
#         ans = 0
#         for val, frq in mp.items():
#             if frq % 2 != 0:
#                 ans ^= val
#         return ans