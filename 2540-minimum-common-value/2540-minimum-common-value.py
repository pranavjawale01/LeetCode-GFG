class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        i , j , m , n = 0, 0, len(nums1), len(nums2)
        while i < n and j < m:
            if nums1[i] == nums2[j]:
                return nums1[i]
            elif nums1[i] > nums2[j]:
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
        return -1